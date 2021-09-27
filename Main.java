package com.company;
import java.util.*;

public class Main {

    static Map<Integer, Float> answer = new HashMap<Integer, Float>();
    static ArrayList<String> variants = new ArrayList<>();

    public static boolean isOperand(char c) {
        return c == '+' || c == '-' || c == '*' || c == '>' || c == '(' || c == ')';
    }

    public static void makeVariants(String s, StringBuilder var, int ctr){
        if(ctr == s.length()){
            variants.add(var.toString());
        }else{
            for (int i = ctr; i < s.length(); i++) {
                if(s.charAt(i) == 'd'){
                    ++i; // Skip 'd'
                    StringBuilder num = new StringBuilder();
                    while(i != s.length() && !isOperand(s.charAt(i))){
                        num.append(s.charAt(i));
                        ++i;
                    }
                    int n = Integer.parseInt(num.toString());
                    for(int j = 1; j <= n; ++j){
                        num = new StringBuilder(var); // reusing num
                        num.append(Integer.toString(j));
                        makeVariants(s, num, i);
                    }
                    break;
                  //  --i; // Decrease i not to skip (+, -, >, etc)
                }else{
                    var.append(s.charAt(i));
                    if(i == s.length()-1){ // case when we reach the end
                        variants.add(var.toString());
                    }
                }
            }
        }
    }

    public static int compute(int a, int b, char op){
//        System.out.printf("%d %c %d %n", a, op, b);
        if(op == '+')
            return a + b;
        else if(op == '-')
            return a - b;
        else if(op == '*')
            return a * b;
        else if(op == '>')
            return a > b ? 1 : 0;
        else{
            System.out.printf("Strange operation '%c'\n", op);
            return 0;
        }
    }

    public static int expressionSolver(String s){
        Stack<Character> ops = new Stack<>();
        Stack<Integer> nums = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            if(isOperand(s.charAt(i))){ // Put into (+, -, >, etc)
                if(s.charAt(i) != ')'){
                    while(!ops.empty()){
                        Character prev = ops.peek(), cur = s.charAt(i);
                        if(((prev == '+' || prev == '-' || prev == '*') && (cur == '+' || cur == '-' || cur == '>'))){
                              //  (prev == '>' && (cur == '+' || cur == '-' || cur == '*'))){
                              //  ((prev == '+' || prev == '-') && cur == '>')){
                            int b = nums.pop(), a = nums.pop();
                            //System.out.println(compute(a, b, ops.peek()));
                            nums.push(compute(a, b, ops.pop()));

                        }else{
                            break;
                        }
                    }
                    ops.push(s.charAt(i));
                }else{
                    while(ops.peek() != '('){
                        int b = nums.pop(), a = nums.pop();
                        nums.push(compute(a, b, ops.pop()));
                    }
                    ops.pop();
                }
            }else{ // Put into (100, 2, d4, etc)
                StringBuilder tmp = new StringBuilder();
                while(i != s.length() && !isOperand(s.charAt(i))){
                    tmp.append(s.charAt(i));
                    ++i;
                }
                --i; // Decrease i not to skip (+, -, >, etc)

                nums.push(Integer.parseInt(tmp.toString()));
            }
        }
        while(!ops.empty()){
            int b = nums.pop(), a = nums.pop();
            nums.push(compute(a, b, ops.pop()));
        }

//        System.out.println(nums.peek());
        return nums.pop();
    }


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String s = in.nextLine();


        StringBuilder var = new StringBuilder();
        int ctr = 0;
        makeVariants(s, var, ctr);

        for (int i = 0; i < variants.size(); i++) {
            int tmp = expressionSolver(variants.get(i));
            if(answer.containsKey(tmp)){
                answer.put(tmp, answer.get(tmp)+1);
            }else{
                int a = 1;
                answer.put(tmp, (float)a);
            }
        }
        Set<Integer> ans = answer.keySet();
        List<Integer> sortedAns = new ArrayList<>(ans);
        Collections.sort(sortedAns);
        for (int i = 0; i < sortedAns.size(); i++) {
            int j = sortedAns.get(i);
            float k = (float)answer.get(j)*100/variants.size();
            System.out.printf("%d %.2f\n", j, k);
        }


    }
}