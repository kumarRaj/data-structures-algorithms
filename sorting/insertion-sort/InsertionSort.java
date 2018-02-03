import java.util.*;
class InsertionSort {
	public static void main(String[] args) {
		int a[] = {62,45,21,56,87,23};
					// {62,62,21,56,87,23};
					// {45,62,21,56,87,23};
					// {45,62,62,56,87,23};
					// {45,45,62,56,87,23};
					// {21,45,62,56,87,23};
					// {21,45,62,62,87,23};
					// {21,45,56,62,87,23};
					// {21,45,56,62,62,87};
					// {21,45,56,56,62,87};
					// {21,23,45,56,62,87};

			int j;
		for (int i = 1; i < a.length; i++) {
			int temp = a[i];
			for (j = i - 1;j >= 0; j--) {
				if (a[j] > temp)
					a[j+1] = a[j];
				else break;
			}
			a[j+1] = temp;
		}
		System.out.println(Arrays.toString(a));
	}
}