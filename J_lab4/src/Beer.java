public class Beer {
    private String name;
    private String style;
    private double strength;


    public Beer(String name, String style, double strength){
        this.name = name;
        this.style = style;
        this.strength = strength;
    }

    public String getName() {
        return name;
    }

    public double getStrength() {
        return strength;
    }

    public String getStyle() {
        return style;
    }

     public String toString(){
        return "Beer{name = " + name + ", style = " + style +", strength = " + strength + "}";
     }
}
