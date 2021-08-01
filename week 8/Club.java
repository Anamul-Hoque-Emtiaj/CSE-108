public class Club {
    private int id;
    private String name;
    private Player[] players;
    private int playerCount=0;

	// you are not allowed to write any other constructor
    public Club() {
        this.players = new Player[11];
    }

	public double getSalary() {
        double total = 0;
        for (int i = 0; i < playerCount; i++) {
            total += players[i].getSalary();
        }
        return total;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void addPlayer(Player players) {
        this.players[playerCount]=players;
        playerCount=playerCount+1;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }
    public Player getMaxSalaryPlayer(){
        double max = -10000,current;
        int index=0;
        for (int i = 0; i < playerCount; i++) {
            current= this.players[i].getSalary();
            if(current>max){
                max=current;
                index=i;
            }
        }
        return this.players[index];
    }
}