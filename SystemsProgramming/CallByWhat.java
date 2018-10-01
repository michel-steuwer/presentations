public class CallByWhat
{
    
    public static class MutablePair {
        public int fst;
        public int snd;
        public MutablePair(int fst, int snd) {
            this.fst = fst;
            this.snd = snd;
        }
    }

    public static void set_int_to_42(int x) {
        x = 42;
    }
    
    public static void set_Integer_to_42(Integer x) {
        x = 42;
    }
    
    public static void set_fst_of_MutablePair_to_42(MutablePair x) {
        x.fst = 42;
    }
    
	public static void main(String[] args) {
	    int x = 41;
	    set_int_to_42(x);
		System.out.println(x);
		
		Integer y = new Integer(41);
		set_Integer_to_42(y);
		System.out.println(y);
		
		MutablePair z = new MutablePair(41, 23);
		set_fst_of_MutablePair_to_42(z);
		System.out.println("{ " + z.fst + ", " + z.snd + " }");
	}
}