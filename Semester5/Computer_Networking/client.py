import socket

def start_client():
    server_ip = '127.0.0.1'  # Localhost
    server_port = 65432      # Port number
    
    # Create a socket and connect to the server
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((server_ip, server_port))
    
    # Receive and display the welcome message
    welcome_message = client_socket.recv(1024).decode()
    print(f"Server: {welcome_message}")
    
    while True:
        message = input("You: ")
        
        if message.lower() == 'exit':
            print("Exiting...")
            break
        
        client_socket.send(message.encode())
        
        server_response = client_socket.recv(1024).decode()
        print(f"Server: {server_response}")
    
    # Close the socket
    client_socket.close()

if __name__ == "__main__":
    start_client()

