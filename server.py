import socket

if __name__ == '__main__':
    ip = "127.0.0.1"
    port = 28563

    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((ip, port))
    server.listen(5)

    while True:

        client, address = server.accept()
        print(f"Connection Establish - {address[1]}, {address[0]}")
        string = client.recv(1024)
        string = string.decode("utf-8")
        client.send(bytes(string, "utf-8"))

        client.close()

