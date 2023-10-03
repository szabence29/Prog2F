import java.util.Comparator;

public class CombinedComparator<T> implements Comparator<T> {
    private final Comparator<T>[] comparators;

    @SafeVarargs
    public CombinedComparator(Comparator<T>... comparators) {
        this.comparators = comparators;
    }

    @Override
    public int compare(T o1, T o2) {
        for (Comparator<T> comparator : comparators) {
            int result = comparator.compare(o1, o2);
            if (result != 0) {
                return result;
            }
        }
        return 0;
    }
}