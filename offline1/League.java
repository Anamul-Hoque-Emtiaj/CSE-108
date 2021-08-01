public class League {
    private Match[] matches;
    private int matchCount;
    private int clubCount;
    private String name;
    private Club[] clubs;
    // add your variables here, if required

    public League() {
        // assume a league can have at most 5 clubs, add code for initialization accordingly
        this.clubs = new Club[5];
        clubCount = 0;
        matchCount = 0;
    }

    public void printLeagueInfo(){
        System.out.println("League : " + name);
        printClubs();
    }

    public void printClubs(){
        System.out.println("Clubs:");
        // print the name of the clubs of this league, each one on a line
        for(int i=0; i<clubCount; i++){
            System.out.println(clubs[i].getName());
        }
    }

    public void scheduleMatches(){
        matchCount = (clubCount*(clubCount-1));
        matches = new Match[matchCount];
        int matchNo = 0;
        for (int i=0; i<clubCount; i++){
            for (int j=0; j<clubCount; j++){
                // check the constructor of the Match class and add your code here
                // note that there will be two matches between club A and club B
                // in the first match, club A will play as the home team and in the second match, as the away team
                if(i!=j){
                    Match match = new Match(matchNo,clubs[i],clubs[j]);
                    matches[matchNo++] = match;
                }
            }
        }
    }

    public void simulateMatches(){
        for (int i=0; i<matchCount; i++){
            matches[i].play();
        }
    }

    public void printMatches(){
        System.out.println("Matches:");
        for (int i=0; i<matchCount; i++){
            matches[i].showResult();
        }
    }

    public void showStandings(){
        // sort the clubs in descending order of points
        // note that, the sequence in which clubs were added to the league, should be unchanged
        // check the given sample output for clarification
        // (carefully observe the output of showStandings() followed by printLeagueInfo() method calls
        // you can use additional arrays if needed
        System.out.println("Sl. - Club - Points");
        Club[] sortedClubs;
        sortedClubs = new Club[clubCount];
        for(int i=0;i<clubCount;i++){
            sortedClubs[i]=clubs[i];
        }
        for(int i=0;i<clubCount;i++){
            for(int j=0; j<clubCount;j++){
                if(sortedClubs[i].getPoint()>sortedClubs[j].getPoint()){
                    Club temp = sortedClubs[i];
                    sortedClubs[i] = sortedClubs[j];
                    sortedClubs[j] = temp;
                }
            }
        }
        for(int i=0;i<clubCount;i++){
            System.out.println((i+1)+ ". "+ sortedClubs[i].getName()+" "+sortedClubs[i].getPoint());
        }
    }
    public void setName(String name) {
        this.name = name;
    }
    public void addClub(Club c){
        clubs[clubCount++]=c;
    }
   public void removeClub(Club c){
        int in=0;
        for(int i=0;i<clubCount;i++){
            if(clubs[i].getId()==c.getId()){
                in=i;
                break;
            }
        }
        for(int i=in; i<clubCount-1;i++){
            clubs[i]=clubs[i+1];
        }
        clubCount--;
   }

    // add your methods here, if required
}

