import java.util.*;
public class NonNegativeSubArray {

	public static void main(String[] args) {
		Integer[] numbers = new Integer[] {2,4,6,8,-1,6,7};
		ArrayList<Integer> array = new ArrayList<Integer>(Arrays.asList(numbers));
		System.out.println(new NonNegativeSubArray().maxset(array));
		System.out.println("-----------------");

		numbers = new Integer[] {756898537, -1973594324, -2038664370, -184803526, 1424268980};
		array = new ArrayList<Integer>(Arrays.asList(numbers));
		System.out.println(new NonNegativeSubArray().maxset(array));
		System.out.println("-----------------");
		
		numbers = new Integer[] {24115, -75629, -46517, 30105, 19451, -82188, 99505, 6752, -36716, 54438, -51501, 83871, 11137, -53177, 22294, -21609, -59745, 53635, -98142, 27968, -260, 41594, 16395, 19113, 71006, -97942, 42082, -30767, 85695, -73671};
		array = new ArrayList<Integer>(Arrays.asList(numbers));
		System.out.println(new NonNegativeSubArray().maxset(array));
		System.out.println("-----------------");


	}

	public ArrayList<Integer> maxset(ArrayList<Integer> A) {
		ArrayList<Integer> temp = new ArrayList<Integer>();
		ArrayList<Integer> sub = new ArrayList<Integer>();
		Long currentSubSum = 0l;
		boolean negativeCount = false;
		Long tempSum = 0l;
		for (Integer x: A) {
			if(x >= 0){
				temp.add(x);
				tempSum += x;
			}
			else {
				negativeCount = true;
				// Long tempSum = temp.stream().mapToLong(i -> i).sum();
				if (tempSum > currentSubSum){
					sub = temp;
					currentSubSum = tempSum;
				}
				else if (tempSum == currentSubSum){
					if (sub.size() < temp.size()){
						sub = temp;
						currentSubSum = tempSum;
					}
				}
				tempSum = 0l;
				temp = new ArrayList<Integer>();
			}
		}
		if (tempSum > currentSubSum){
			sub = temp;
		}
		else if (tempSum == currentSubSum){
			if (sub.size() < temp.size()){
				sub = temp;
			}
		}

		if (!negativeCount){
			return A;
		}
		return sub;
    }
}
