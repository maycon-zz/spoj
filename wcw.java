import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		
		for (int i = 0; i < T; i++) {
			int N = Integer.parseInt(in.readLine());
			int[] intVals = new int[N + 1];
			
			StringTokenizer st = new StringTokenizer(in.readLine(), " ");
			int j = 1;
			while (st.hasMoreElements()) {
				intVals[j] = Integer.parseInt(st.nextElement().toString());
				j++;
			}

			int d = 0;
			for (j = 1; j <= N; j++) {
				while (intVals[j] != j) {
					intVals[intVals[j]] = (intVals[intVals[j]] + intVals[j]) - (intVals[j] = intVals[intVals[j]]);
					d++;
				}
			}
			
			System.out.println(d);
		}
	}
}
