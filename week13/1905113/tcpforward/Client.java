package tcpforward;

import util.NetworkUtil;

import java.io.IOException;
import java.util.List;
import java.util.Scanner;

public class Client {
    private boolean isConnected;
    private String serverAddress;
    private int serverPort;
    private NetworkUtil networkUtil;
    private String clientName;

    public Client(String serverAddress, int serverPort) {
        this.serverAddress = serverAddress;
        this.serverPort = serverPort;
        this.isConnected = false;
    }

    public void connect(String name){
        try {
            networkUtil = new NetworkUtil(serverAddress, serverPort);
            networkUtil.write(name);
            new ReadThreadClient(networkUtil);
            this.isConnected = true;
            this.clientName = name;
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public List<String> getClientList() {
        try {
            networkUtil.write("2");
            List<String> clientList = (List<String>) networkUtil.read();
            return clientList;

        }catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    public static void main(String args[]) throws IOException {
        String serverAddress = "127.0.0.1";
        int serverPort = 33333;
        Client client = new Client(serverAddress, serverPort);
        while (true){
            System.out.println("Enter 1 for Connect to server, 2 for getting client list,\n" +
                    "3 for sending message to particular client, 4 for Broadcasting");
            Scanner scanner = new Scanner(System.in);
            String option = scanner.nextLine();
            option = option.trim();
            List<String> clientList;
            if(option.equals("1")){
                System.out.print("Enter name of the client: ");
                String clientName = scanner.nextLine();
                client.connect(clientName);
            }else if(option.equals("2")&& client.isConnected){
                clientList = client.getClientList();
                for(String str: clientList){
                    System.out.println(str);
                }
            }else if(option.equals("3")&& client.isConnected){
                WriteThreadClient w = new WriteThreadClient(client.networkUtil, client.clientName);
                try {
                    w.getThr().join();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }else if(option.equals("4")&& client.isConnected){
                WriteBroadcast w = new WriteBroadcast(client.networkUtil, client.clientName);
                try {
                    w.getThr().join();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            } else{
                System.out.println("Error occur!! Plz connect first then choose correct option");
            }
        }
    }
}


