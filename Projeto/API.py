import serial, time, requests

PORT = "COM3"   
BAUD = 9600

arduino = serial.Serial(PORT, BAUD, timeout=1)
time.sleep(2)

cot = {"USD":0.0, "EUR":0.0, "BTC":0.0}

def obter_cotacoes():
    r = requests.get(
        "https://economia.awesomeapi.com.br/json/last/USD-BRL,EUR-BRL,BTC-BRL",
        timeout=10).json()
    cot["USD"] = float(r["USDBRL"]["bid"])
    cot["EUR"] = float(r["EURBRL"]["bid"])
    cot["BTC"] = float(r["BTCBRL"]["bid"])

def enviar_cotacoes():
    arduino.write(b"@CMDExibindo moedas...\n"); time.sleep(1)
    arduino.write(f"@CMDUSD: R${cot['USD']:.2f}\n".encode()); time.sleep(4)
    arduino.write(f"@CMDEUR: R${cot['EUR']:.2f}\n".encode()); time.sleep(4)
    arduino.write(f"@CMDBTC: R${cot['BTC']:.0f}\n".encode()); time.sleep(4)

def tratar_pedido(linha:str):
    try:
        valor, moeda = linha.split(",")
        valor = float(valor)
    except ValueError:
        return
    if moeda not in cot:
        return
    conv = round(valor / cot[moeda], 6 if moeda == "BTC" else 2)
    arduino.write(f"{valor},{moeda},{conv}\n".encode())

# Primeira rodada
obter_cotacoes()
enviar_cotacoes()

try:
    while True:
        linha = arduino.readline().decode().strip()
        if not linha:
            continue
        if linha == "REQ_QUOTES":
            obter_cotacoes()
            enviar_cotacoes()
        elif linha.count(",") == 1:
            tratar_pedido(linha)
except KeyboardInterrupt:
    pass
finally:
    arduino.close()
