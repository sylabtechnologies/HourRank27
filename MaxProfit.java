// https://www.tangiblesoftwaresolutions.com/free_editions.html

import java.io.*;
import java.util.*;

class max_profit {

BufferedReader br;
PrintWriter out;
long inf = (long)2e18;

void solve() {
    int n = ni();
    assert (n >= 1 && n <= 300000) : "Invalid input";
    int profit_factor[] = new int[n];
    for(int i = 0; i < n; i++) {
        profit_factor[i] = ni();
        assert (profit_factor[i] >= (int)(-1e6) && profit_factor[i] <= (int)1e6) : "Invalid data";
    }
    if(n < 3){
        out.println(-1);
        return;
    }
    TreeMap<Integer, Integer> right_map = new TreeMap<>();
    for(int i = 1; i < n; i++){
        int key = profit_factor[i];
        if(right_map.containsKey(key)) {
            right_map.put(key, right_map.get(key) + 1);
        } else {
            right_map.put(key, 1);
        }
    }

    long val, ans = -inf;
    Integer left, current;
    Map.Entry right;
    TreeSet<Integer> left_set = new TreeSet<>();

    for(int i = 1; i < n-1; i++){
        current = profit_factor[i];
        left_set.add(profit_factor[i-1]);

        if(right_map.get(current) > 1)	{
            right_map.put(current, right_map.get(current) - 1);
        } else {	
            right_map.remove(current);
        }

        left = left_set.lower(current);
        if(left != null){
            right = right_map.higherEntry(current);
            if(right != null){
            val = 1L * left * current * (Integer)right.getKey();
                if(val > ans)	ans = val;
            }

            right = right_map.lastEntry();
            if(right != null && (Integer)right.getKey() > current){
            val = 1L * left * current * (Integer)right.getKey();
                if(val > ans)	ans = val;
            }
        }

        left = left_set.first();
        if(left != null && left < current){
            right = right_map.higherEntry(current);
            if(right != null){
            val = 1L * left * current * (Integer)right.getKey();
                if(val > ans)	ans = val;
            }

            right = right_map.lastEntry();
            if(right != null && (Integer)right.getKey() > current){
            val = 1L * left * current * (Integer)right.getKey();
                if(val > ans)	ans = val;
            }
        }
    }

    if(ans == -inf)	ans = -1;
    out.println(ans);
}

void run(){
    br = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(System.out);
    solve();
    out.flush();
}

int ni() {
    return Integer.parseInt(ns());
}

String ip[];
int ip_ptr, ip_size;

String ns() {
    if(ip_ptr >= ip_size){
        try{
            ip = br.readLine().split(" ");
            ip_size = ip.length;
            ip_ptr = 0;
        }catch(IOException e){
            throw new InputMismatchException();
        }
        if(ip_size <= 0)	return "-1";
    }
    return ip[ip_ptr++];
}

public static void main(String[] args) {
    new max_profit().run();
}
}