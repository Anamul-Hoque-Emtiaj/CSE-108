import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static final String FILE_NAME = "players.txt";

    private static List<Player> Players;

    public static void readFromFile() throws Exception {
        Players = new ArrayList();
        BufferedReader br = new BufferedReader(new FileReader(FILE_NAME));
        while (true) {
            String line = br.readLine();
            if (line == null) break;
            String[] tokens = line.split(",");
            Player player = new Player();
            player.setName(tokens[0]);
            player.setCountry(tokens[1]);
            player.setAge(Integer.parseInt(tokens[2]));
            player.setHeight(Double.parseDouble(tokens[3]));
            player.setClub(tokens[4]);
            player.setPosition(tokens[5]);
            player.setNumber(Integer.parseInt(tokens[6]));
            player.setWeeklySalary(Double.parseDouble(tokens[7]));
            Players.add(player);
        }
        br.close();
    }

    public static void writeToFile() throws Exception {
        BufferedWriter bw = new BufferedWriter(new FileWriter(FILE_NAME));
        for (Player player : Players) {
            bw.write(player.getName() + "," + player.getCountry() + "," + player.getAge() + "," + player.getHeight()
                    + "," + player.getClub()+ "," + player.getPosition()+ "," + player.getNumber()+ "," + player.getWeeklySalary());
            bw.write("\n");
        }
        bw.close();
    }

    public static boolean searchPlayerByName(String name){
        boolean result = false;
        for(Player player: Players){
            if(player.getName().equalsIgnoreCase(name)){
                result=true;
                player.showPlayerInfo();
                break;
            }

        }
        return result;
    }

    public static boolean searchPlayers(String club, String country){
        boolean result = false;
        if(club.equalsIgnoreCase("ANY")){
            for(Player player: Players){
                if(player.getCountry().equalsIgnoreCase(country)){
                    result=true;
                    player.showPlayerInfo();
                }
            }
        }
        else{
            for(Player player: Players){
                if(player.getCountry().equalsIgnoreCase(country) && player.getClub().equalsIgnoreCase(club)){
                    result=true;
                    player.showPlayerInfo();
                }

            }
        }
        return result;
    }

    public static boolean searchPlayers(String position){
        boolean result = false;
        for(Player player: Players){
            if(player.getPosition().equalsIgnoreCase(position)){
                result=true;
                player.showPlayerInfo();
            }

        }
        return result;
    }

    public static boolean searchPlayers(double lowerLimit, double upperLimit){
        if(lowerLimit>upperLimit){
            System.out.println("Plz provide correct input following input format");
            return true;
        }
        boolean result = false;
        for(Player player: Players){
            double salary = player.getWeeklySalary();
            if(salary>=lowerLimit&& salary<=upperLimit){
                result=true;
                player.showPlayerInfo();
            }
        }
        return result;
    }

    public static void playerCount(){
        List<String> Country = new ArrayList();
        for(Player player: Players){
            if(!Country.contains(player.getCountry()))
                Country.add(player.getCountry());
        }
        for(String country: Country){
            int count = 0;
            for(Player player: Players){
                if(player.getCountry().equalsIgnoreCase(country))
                    count++;
            }
            System.out.println(count+" players from "+country);
        }
    }

    public static boolean isClub(String club){
        boolean result = false;
        for(Player player: Players){
            if(player.getClub().equalsIgnoreCase(club)){
                result = true;
                break;
            }
        }
        return result;
    }
    public static void totalYearlySalary(String club){
        double salary=0;
        for(Player player: Players){
            if(player.getClub().equalsIgnoreCase(club)){
                salary+=player.getWeeklySalary();
            }
        }
        salary*=52.0;
        System.out.printf("\nTotal yearly salary of %s is %10f\n",club,salary);
    }
    public static void playersWithMaximumHeight(String club){
        double max=-1,temp;
        for(Player player: Players){
            if(player.getClub().equalsIgnoreCase(club)){
                temp = player.getHeight();
                if(temp>max)
                    max=temp;
            }
        }
        for(Player player: Players){
            if(player.getHeight()==max&&player.getClub().equalsIgnoreCase(club))
                player.showPlayerInfo();
        }
    }

    public static void playersWithMaximumAge(String club){
        int max=-1,temp;
        for(Player player: Players){
            if(player.getClub().equalsIgnoreCase(club)){
                temp = player.getAge();
                if(temp>max)
                    max=temp;
            }
        }
        for(Player player: Players){
            if(player.getAge()==max&&player.getClub().equalsIgnoreCase(club))
                player.showPlayerInfo();
        }
    }

    public static void playersWithMaximumWeeklySalary(String club){
        double max=-1,temp;
        for(Player player: Players){
            if(player.getClub().equalsIgnoreCase(club)){
                temp = player.getWeeklySalary();
                if(temp>max)
                    max=temp;
            }
        }
        for(Player player: Players){
            if(player.getWeeklySalary()==max&&player.getClub().equalsIgnoreCase(club))
                player.showPlayerInfo();
        }
    }

    public static boolean canAdd(String club, String name, String position, int number){
        int count=0;
        for(Player player: Players){
            if(player.getClub().equalsIgnoreCase(club)){
                count++;
                if(player.getNumber()==number){
                    System.out.println("This Number already exist in this club");
                    return false;
                }
            }
            if(player.getName().equalsIgnoreCase(name)){
                System.out.println("Player with this name already exist");
                return false;
            }
        }
        if(count>=7){
            System.out.println("Club's players capacity is full");
            return false;
        }
        String[] str = {"Goalkeeper","Defender","Midfielder","Forward"};
        boolean validPosition = false;
        for(String s: str){
            if(s.equalsIgnoreCase(position))
                validPosition = true;
        }
        if(!validPosition)
            System.out.println("Invalid Position given");
        return validPosition;
    }

    public static void main(String[] args) throws Exception{
        readFromFile();
        Scanner scn = new Scanner(System.in);
        System.out.println("\n\n-----Main Menu-----\n\n");
        while (true){
            System.out.println("\nEnter 1 for Search Players, 2 for Search Clubs, 3 for Add Player, 4 for Exit System");
            String option = scn.nextLine();
            option = option.trim();
            if(option.equals("4")){
                writeToFile();
                break;
            }
            else if(option.equals("3")){
                System.out.println("\n\n-----Add player Menu-----\n\n");
                while (true){
                    System.out.println("\nEnter player's information following bellow format\n" +
                            "(Name,Country,Age,Height,Club,Position,Number,WeeklySalary) or 1 for back to main:");
                    String player = scn.nextLine();
                    player = player.trim();
                    if(player.equalsIgnoreCase("1")){
                        System.out.println("\n\n-----Return to Main Menu from Add Player Menu-----\n\n");
                        break;
                    }
                    try{
                        String[] playerDetails = player.split(",");
                        String Name = playerDetails[0].trim();
                        String Country = playerDetails[1].trim();
                        int Age = Integer.parseInt(playerDetails[2].trim());
                        double Height = Double.parseDouble(playerDetails[3].trim());
                        String Club = playerDetails[4].trim();
                        String Position = playerDetails[5].trim();
                        int Number = Integer.parseInt(playerDetails[6].trim());
                        double WeeklySalary = Double.parseDouble(playerDetails[7].trim());
                        boolean canPlayerAdd = canAdd(Club,Name,Position,Number);
                        if(canPlayerAdd){
                            Player player1 = new Player(Name,Country,Age,Height,Club,Position,Number,WeeklySalary);
                            Players.add(player1);
                            System.out.println("Player added successfully");
                            System.out.println("\n\n-----Return to Main Menu from Add Player Menu-----\n\n");
                            break;
                        }
                    }catch (Exception e){
                        System.out.println("Invalid Input given!!plz provide correct input following input format");
                    }
                }
            }
            else if(option.equals("2")){
                System.out.println("\n\n-----Search Clubs Menu-----\n\n");
                while (true){
                    System.out.println("\nSelect Club Searching Options - Enter 1 for players search with the maximum salary, 2 for with the maximum age,\n" +
                            "3 for with the maximum height, 4 for total yearly salary of the club, 5 for back to Main menu");
                    String searchClubOption = scn.nextLine();
                    searchClubOption = searchClubOption.trim();
                    if(searchClubOption.equals("5")){
                        System.out.println("\n\n-----Return to Main Menu from Club Search Menu-----\n\n");
                        break;
                    }
                    else if(searchClubOption.equals("4")){
                        System.out.println("Enter Club's Name:");
                        String club = scn.nextLine();
                        club = club.trim();
                        boolean isFound=isClub(club);
                        if(!isFound){
                            System.out.println("No such club with this name");
                        }
                        else{
                            totalYearlySalary(club);
                        }
                    }
                    else if(searchClubOption.equals("3")){
                        System.out.println("Enter Club's Name:");
                        String club = scn.nextLine();
                        club = club.trim();
                        boolean isFound=isClub(club);
                        if(!isFound){
                            System.out.println("No such club with this name");
                        }
                        else{
                            System.out.println("\nPlayers with the maximum height of "+club+" club\n");
                            playersWithMaximumHeight(club);
                        }
                    }
                    else if(searchClubOption.equals("2")){
                        System.out.println("Enter Club's Name:");
                        String club = scn.nextLine();
                        club = club.trim();
                        boolean isFound=isClub(club);
                        if(!isFound){
                            System.out.println("No such club with this name");
                        }
                        else{
                            System.out.println("\nPlayers with the maximum age of "+club+" club\n");
                            playersWithMaximumAge(club);
                        }
                    }
                    else if(searchClubOption.equals("1")){
                        System.out.println("Enter Club's Name:");
                        String club = scn.nextLine();
                        club = club.trim();
                        boolean isFound=isClub(club);
                        if(!isFound){
                            System.out.println("No such club with this name");
                        }
                        else{
                            System.out.println("\nPlayers with the maximum weekly salary of "+club+" club\n");
                            playersWithMaximumWeeklySalary(club);
                        }
                    }
                    else{
                        System.out.println("Invalid Input given!! Select your option again");
                    }
                }
            }
            else if(option.equals("1")){
                System.out.println("\n\n-----Search Players Menu-----\n\n");
                while (true){
                    System.out.println("\nSelect Player Searching Options - Enter 1 for By Player Name, 2 for By Club and Country, \n" +
                            "3 for By Position, 4 for By Salary Range, 5 for Country-wise player count, 6 for Back to Main Menu:");
                    String searchPlayerOption = scn.nextLine();
                    searchPlayerOption = searchPlayerOption.trim();
                    if(searchPlayerOption.equals("6")){
                        System.out.println("\n\n-----Return to Main Menu from Players Search Menu-----\n\n");
                        break;
                    }
                    else if(searchPlayerOption.equals("5")){

                        System.out.println("\nCountry-wise player counts: ");
                        playerCount();
                    }
                    else if(searchPlayerOption.equals("4")){
                        System.out.println("\nSearching players by salary range\n");
                        System.out.println("Enter  LowerLimit,UpperLimit:");
                        String salary = scn.nextLine();
                        salary = salary.trim();
                        String[] Salary = salary.split(",");
                        if(Salary.length==2){
                            try{
                                boolean isFound=searchPlayers(Double.parseDouble(Salary[0].trim()),Double.parseDouble(Salary[1].trim()));
                                if(!isFound){
                                    System.out.println("No such player with this weekly salary range");
                                }
                            }catch (Exception e){
                                System.out.println("Invalid Input given!! plz provide two double following input format");
                            }
                        }
                        else{
                            System.out.println("Invalid Input given!!plz follow input formatting");
                        }

                    }
                    else if(searchPlayerOption.equals("3")){
                        System.out.println("\nSearching players by position\n");
                        System.out.println("Enter Player's Position:");
                        String position = scn.nextLine();
                        position = position.trim();
                        boolean isFound=searchPlayers(position);
                        if(!isFound){
                            System.out.println("No such player with this position");
                        }
                    }
                    else if(searchPlayerOption.equals("2")){
                        System.out.println("\nSearching players by country's name and club's name\n");
                        System.out.println("Enter Country's Name,Club's Name:");
                        String str = scn.nextLine();
                        str = str.trim();
                        String[] Str = str.split(",");
                        if(Str.length==2){
                            boolean isFound=searchPlayers(Str[1].trim(),Str[0].trim());
                            if(!isFound){
                                System.out.println("No such player with this country and club");
                            }
                        }
                        else{
                            System.out.println("Invalid Input given!!plz follow input formatting");
                        }
                    }
                    else if(searchPlayerOption.equals("1")){
                        System.out.println("\nSearching players by player's name\n");
                        System.out.println("Enter Player's Name:");
                        String name = scn.nextLine();
                        name = name.trim();
                        boolean isFound=searchPlayerByName(name);
                        if(!isFound){
                            System.out.println("No such player with this name");
                        }
                    }
                    else{
                        System.out.println("Invalid Input given!! Select your option again");
                    }
                }
            }
            else{
                System.out.println("Invalid Input given!! Select your option again");
            }
        }
    }

}
