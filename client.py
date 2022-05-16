import socket


if __name__ == '__main__':
    ip = "127.0.0.1"
    port = 28563

    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.connect((ip, port))
    print("Client's command:\n1. Send message\n2. Get a message \n3. Exit")
    string = "No new messages"
    buffer = []
    while True:
        command = input("Enter command: ")
        if command =="1":
            string = input("Enter message: ")
            server.send(bytes(string, "utf-8"))
        if command == "2":
            server.send(bytes(string, "utf-8"))
            buffer = server.recv(1024)
            buffer = buffer.decode("utf-8")
            print(f"New message: {buffer}")
        if command == "3":
            break
