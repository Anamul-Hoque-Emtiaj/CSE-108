public class Club {
    private String name;
    private int point;
    private int id;
    public Club() {
        point=0;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getId() {
        return id;
    }

    public void setPoint(int point){
        this.point = point;
    }
    public int getPoint(){
        return point;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getName() {
        return name;
    }
}