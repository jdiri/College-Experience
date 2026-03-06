import socket
import threading
import datetime

def handle_client(client_socket, client_address):
    print(f"New connection from {client_address}")
    
    client_socket.send(f"Hello, {client_address}!".encode())
    
    while True:
        try:
            message = client_socket.recv(1024).decode()
            
            if not message:
                print(f"Client {client_address} has disconnected.")
                break
            
            if message.lower() == 'exit':
                print(f"Client {client_address} has disconnected.")
                break
            
            timestamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
            print(f"[{timestamp}] {client_address}: {message}")
            
            client_socket.send(f"Server: {message}".encode())
        
        except Exception as e:
            print(f"Error with client {client_address}: {e}")
            break
    
    client_socket.close()

def start_server():
    server_ip = '127.0.0.1'  # Localhost
    server_port = 65432      # Port number

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((server_ip, server_port))
    server_socket.listen(5)

    print(f"Server listening on {server_ip}:{server_port}...")

    while True:
        client_socket, client_address = server_socket.accept()
        client_handler = threading.Thread(target=handle_client, args=(client_socket, client_address))
        client_handler.start()

if __name__ == "__main__":
    start_server()

