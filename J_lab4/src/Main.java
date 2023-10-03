import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Main beers = new Main();

        Beer b1 = new Beer("Dreher", "lager", 4.5);
        Beer b2 = new Beer("Heineken", "lager", 4.6);

        System.out.println(b1.toString());
        System.out.println(b2.toString());

        System.out.println("---------");

        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNextLine()) {
            String[] parancs = scanner.nextLine().split(" ");
            System.out.println(parancs[0] + ", szamlalo: " + parancs.length);

            if (parancs[0].equals("exit")){
                System.exit(0);
            }
            if (parancs[0].equals("add") && parancs.length >= 4){
                beers.add(new Beer(parancs[1], parancs[2], Double.parseDouble(parancs[3])));
            }
            if (parancs[0].equals("list")){
                beers.list(parancs.length > 1 ? parancs[1] : "");
            }
            if (parancs[0].equals("save") && parancs.length >= 2){
                String filename = parancs[1];
                try {
                    beers.save(filename);
                    System.out.println("Sikeres mentés!");
                } catch (IOException e){
                    System.err.println("Hiba történt a mentés közben: " + e.getMessage());
                }
            }
            if (parancs[0].equals("load") && parancs.length >= 2){
                String filename = parancs[1];
                try {
                    beers.load(filename);
                    System.out.println("Sikeres betöltés!");
                } catch (IOException | ClassNotFoundException e){
                    System.err.println("Hiba történt a mentés közben: " + e.getMessage());
                }
            }
            if (parancs[0].equals("search") && parancs.length >= 2){
                beers.search(parancs[1]);
            }
            if (parancs[0].equals("find") && parancs.length >= 2){
                beers.find(parancs[1]);
            }
            if (parancs[0].equals("delete") && parancs.length >=2){
                beers.delete(parancs[1]);
            }

        }
    }
    protected ArrayList<Beer> beerlist = new ArrayList<>();
    protected void add(Beer beer){
        beerlist.add(beer);
    }

    protected void list(String c) {
        List<Comparator<Beer>> comparators = new ArrayList<>();

        switch (c) {
            case "name":
                comparators.add(new NameComparator());
                break;
            case "style":
                comparators.add(new StyleComparator());
                break;
            case "strength":
                comparators.add(new StrengthComparator());
                break;
            default:
                System.err.println("Ismeretlen rendezési kritérium: " + c);
                return;
        }

        Comparator<Beer> combinedComparator = new CombinedComparator<>(comparators.toArray(new Comparator[0]));
        List<Beer> sortedBeers = new ArrayList<>(beerlist);
        Collections.sort(sortedBeers, combinedComparator);

        System.out.println("Rendezett sörök:");
        for (Beer beer : sortedBeers) {
            System.out.println(beer.toString());
        }
    }

    protected void save(String file) throws IOException{
        BufferedWriter writer = new BufferedWriter(new FileWriter(file));

        for (Beer beer : beerlist) {
            writer.write(beer.getName() + "," + beer.getStyle() + "," + beer.getStrength());
            writer.newLine();
        }

        writer.close();
    }

    protected void load(String file) throws IOException, ClassNotFoundException{
        BufferedReader reader = new BufferedReader(new FileReader(file));
        String line;

        beerlist.clear();

        while ((line = reader.readLine()) != null) {
            String[] parts = line.split(",");
            if (parts.length == 3) {
                String name = parts[0];
                String style = parts[1];
                double strength = Double.parseDouble(parts[2]);
                Beer beer = new Beer(name, style, strength);
                beerlist.add(beer);
            }
        }

        reader.close();
    }

    protected void search(String name){
        System.out.println("Sörök név szerinti keresése (" + name + "):");
        boolean found = false;
        for (Beer beer : beerlist){
            if(beer.getName().equalsIgnoreCase(name)){
                System.out.println(beer.toString());
                found = true;
            }
        }
        if (!found){
            System.out.println("Nem található ilyen sör.");
        }
    }

    protected void find(String text){
        System.out.println("Szabad szöveges keresés (" + text + "):");
        boolean found = false;
        for (Beer beer : beerlist){
            if(beer.getName().toLowerCase().contains(text.toLowerCase())){
                System.out.println(beer.toString());
                found = true;
            }
        }
        if (!found){
            System.out.println("Nincs találat a (" + text + ") szövegere.");
        }
    }

    protected void delete(String name){
        Iterator<Beer> iterator = beerlist.iterator();
        boolean deleted = false;
        while (iterator.hasNext()) {
            Beer beer = iterator.next();
            if(beer.getName().equalsIgnoreCase(name)){
                iterator.remove();
                System.out.println("Sör törölve: " + beer.toString());
                deleted = true;
            }
        }
        if (!deleted){
            System.out.println("Nincs találat a(z) " + name + "nevű sörre.");
        }
    }
}