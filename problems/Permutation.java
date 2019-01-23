import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.Map;
import java.util.HashMap;
import java.util.Map.Entry;

public class Permutation
{
	static Map<String, Boolean> permutations = new HashMap<>();
	
    public static void main(String[] args)
    {
    	String str = "ABCD";
        new Permutation().permute(str, 0);
        System.out.println(permutations.size());
        for (Map.Entry<String, Boolean> entry : permutations.entrySet()) {
            System.out.println(entry.getKey());
        }
    }
    private void permute(String str, int currentIndex)
    {
        if(currentIndex == str.length()) { 
            permutations.put(str, true);
        	return;
        }
        for (int i = currentIndex; i < str.length() ;i++ ) {
            String result = swap(str, i, currentIndex);
            permute(result, currentIndex + 1);
        }
    }

    public String swap(String a, int i, int j)
    {
    	if(i==j)
    		return a;
        char temp;
        char[] charArray = a.toCharArray();
        temp = charArray[i] ;
        charArray[i] = charArray[j];
        charArray[j] = temp;
        return String.valueOf(charArray);
    }
 
}
