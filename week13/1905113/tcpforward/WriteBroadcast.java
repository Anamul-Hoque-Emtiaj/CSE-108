package tcpforward;

import util.NetworkUtil;

import java.io.IOException;
import java.util.Scanner;

public class WriteBroadcast implements Runnable {

    private Thread thr;
    private NetworkUtil networkUtil;
    String name;

    public WriteBroadcast(NetworkUtil networkUtil, String name) {
        this.networkUtil = networkUtil;
        this.name = name;
        this.thr = new Thread(this);
        thr.start();
    }
    public Thread getThr() {
        return thr;
    }
    public void run() {
        try {
            Scanner input = new Scanner(System.in);
            String from = name;
            String to = "All";
            System.out.print("Enter the broadcast message: ");
            String text = input.nextLine();
            Message message = new Message();
            message.setFrom(from);
            message.setTo(to);
            message.setText(text);
            networkUtil.write(message);
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}



