public class perf_java {
    static long N = (1024L*1024L*16L);
    static double x[];

    public static void setup() {
        long i;
	x = new double[(int)N];
	for (i=0;i<N;i++) { 
	    x[(int)i]=(double)i;
	}
    }
  
    public static void main(String[] args) {
	long i;
	setup();
 
	double s=0;
  
	for (i=0;i<N;i++) { 
	    s+=x[(int)i];
	}
	
	System.out.println(String.format("summed %d doubles in Java, result %f",N,s));
    }
}
