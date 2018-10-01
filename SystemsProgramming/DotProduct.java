public class DotProduct {
    public static void main(String[] args) {
        double[] x = {1, 3, -5};
        double[] y = {4, -2, -1};

        double z = 0;
        for (int i = 0; i < 3; i++) {
            z += x[i] * y[i];
        }
        System.out.println(z);
    }
}