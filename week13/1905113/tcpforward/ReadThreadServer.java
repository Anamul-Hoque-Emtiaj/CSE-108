package tcpforward;

import util.NetworkUtil;

import java.io.IOException;
import java.util.HashMap;
import java.util.List;

public class ReadThreadServer implements Runnable {
    private Thread thr;
    private NetworkUtil networkUtil;
    public HashMap<String, NetworkUtil> clientMap;
    public List<String> clientList;


    public ReadThreadServer(HashMap<String, NetworkUtil> map, List<String> clientList, NetworkUtil networkUtil) {
        this.clientMap = map;
        this.networkUtil = networkUtil;
        this.clientList = clientList;
        this.thr = new Thread(this);
        thr.start();
    }

    public void run() {
        try {
            while (true) {
                Object o = networkUtil.read();
                if(o instanceof String){
                    String option = (String) o;
                    if(option.equals("2")){
                        networkUtil.write(clientList);
                    }
                }
                else if (o instanceof Message) {
                    Message obj = (Message) o;
                    String to = obj.getTo();
                    if(to.equalsIgnoreCase("All")){
                        for(String client: clientList){
                            NetworkUtil nu = clientMap.get(client);
                            if (nu != null && nu!=networkUtil) {
                                nu.write(obj);
                            }
                        }
                    }else{
                        NetworkUtil nu = clientMap.get(to);
                        if (nu != null) {
                            nu.write(obj);
                        }
                    }
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}



