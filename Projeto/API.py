import serial
import time
import requests

# Configurações
porta_serial = 'COM15'
baud_rate = 9600

# Conecta com Arduino
arduino = serial.Serial(porta_serial, baud_rate)
time.sleep(2)

def exibir_cotacoes():
    arduino.write("@CMDExibindo moedas...\n".encode())
    time.sleep(2)

    url = "https://economia.awesomeapi.com.br/json/last/USD-BRL,EUR-BRL,BTC-BRL"
    resposta = requests.get(url).json()

    global cotacao_dolar, cotacao_euro, cotacao_bitcoin
    cotacao_dolar = float(resposta['USDBRL']['bid'])
    cotacao_euro = float(resposta['EURBRL']['bid'])
    cotacao_bitcoin = float(resposta['BTCBRL']['bid'])

    arduino.write(f"@CMDUSD: R${cotacao_dolar:.2f}\n".encode())
    time.sleep(3)
    arduino.write(f"@CMDEUR: R${cotacao_euro:.2f}\n".encode())
    time.sleep(3)
    arduino.write(f"@CMDBTC: R${cotacao_bitcoin:.0f}\n".encode())
    time.sleep(3)

while True:
    exibir_cotacoes()

    arduino.write("@CMDConverter agora?\n".encode())
    time.sleep(2)
    arduino.write("@CMD1=Sim 2=Repetir\n".encode())

    
    escolha = input("Escolha o numero: ")

    if escolha.strip() == "1":
        break  

arduino.write("@CMDDigite valor em R$ no terminal\n".encode())
valor_reais = float(input("Digite o valor para converter: R$ "))

arduino.write("@CMDEscolha: 1=USD 2=EUR 3=BTC\n".encode())
opcao = input("Digite o numero: ")

if opcao == '1':
    convertido = round(valor_reais / cotacao_dolar, 2)
    tipo = "USD"
elif opcao == '2':
    convertido = round(valor_reais / cotacao_euro, 2)
    tipo = "EUR"
elif opcao == '3':
    convertido = round(valor_reais / cotacao_bitcoin, 6)
    tipo = "BTC"
else:
    print("Opção inválida.")
    arduino.write("@CMDErro na opcao\n".encode())
    arduino.close()
    exit()

mensagem = f"{valor_reais},{tipo},{convertido}\n"
arduino.write(mensagem.encode())
print(f"\nEnviado para o Arduino")

arduino.close()
