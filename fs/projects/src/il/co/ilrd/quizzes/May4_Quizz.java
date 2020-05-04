package il.co.ilrd.quizzes;

import java.util.ArrayList;
import java.util.List;

public class May4_Quizz {
	
	int[] orders;
	int next_free_idx = 0;
	int total_orders_ammount;
	
	public May4_Quizz(int total_orders_ammount) {
		
		this.total_orders_ammount = total_orders_ammount;
		orders = new int[total_orders_ammount];
		
	}
	
	public void record (int order_id) {
		orders[next_free_idx % total_orders_ammount] = order_id;
		next_free_idx = (next_free_idx + 1) % total_orders_ammount;
		System.out.println("next free:" + next_free_idx);
	}
	
	public int get_last(int idx) {
		return orders[total_orders_ammount - (idx + 1)];
	}
	
	public static void main (String[] argv) {
		
		//arr[20]
		May4_Quizz m = new May4_Quizz(10);
		
		m.record(10);
		m.record(20);
		m.record(30);
		m.record(40);
		m.record(50);
		m.record(60);
		m.record(70);
		m.record(80);
		m.record(90);
		m.record(100);
		m.record(1);

		
		System.out.println(m.get_last(0));
	}

}
