package il.co.ilrd.pair;

import static org.junit.jupiter.api.Assertions.*;

import java.util.Comparator;

import org.junit.jupiter.api.Test;

class EmployeeNoCmp {
	
	String name;
	int rank;
	
	public EmployeeNoCmp(String name, int rank) {
		this.name = name;
		this.rank = rank;
	}

	@Override
	public String toString() {
		return "Name: " + name + " Rank: "+ rank;
	}

}

class EmployeCmp implements Comparable<EmployeCmp> {
	
	String name;
	int rank;
	
	public EmployeCmp(String name, int rank) {
		this.name = name;
		this.rank = rank;
	}

	@Override
	public String toString() {
		return "Name: " + name + " Rank: "+ rank;
	}

	@Override
	public int compareTo(EmployeCmp o) {
		return this.rank - o.rank;
	}

}

class EmployeeComperator implements Comparator<EmployeeNoCmp>{

	@Override
	public int compare(EmployeeNoCmp o1, EmployeeNoCmp o2) {
		return o1.rank - o2.rank;
	}
}

class PairTest {
	
	@Test 
	void testPair(){
		
		Pair p = Pair.of("A", 10);
		assertEquals(10, p.getValue());
		assertEquals("A", p.getKey());

		
	}
	@Test
	void testMinMax() {
		Integer[] int_array = {2,8,3,1,0};
		Character [] char_array = {'E','A','O','Z'};
		
		Pair<Integer, Integer> pA = Pair.minMax(int_array);
		System.out.println(pA);
		
		assertEquals(0, pA.getKey());
		assertEquals(8, pA.getValue());
		
		Pair <Character, Character> pB = Pair.minMax(char_array);
		System.out.println(pB);

		assertEquals('A', pB.getKey());
		assertEquals('Z', pB.getValue());
	}
	
	@Test
	void testMinMaxCmp() {
		EmployeeNoCmp[] emNCmp = new EmployeeNoCmp[5];
		
		emNCmp[0] = new EmployeeNoCmp("A", 33);
		emNCmp[1] = new EmployeeNoCmp("B", 4);
		emNCmp[2] = new EmployeeNoCmp("C", 3);
		emNCmp[3] = new EmployeeNoCmp("D", 432);
		emNCmp[4] = new EmployeeNoCmp("E", 0);

		Pair pNCmp = Pair.minMax(emNCmp, new EmployeeComperator());
		System.out.println(pNCmp);
		
		EmployeCmp[] emCmp = new EmployeCmp[5];
		
		emCmp[0] = new EmployeCmp("F", 5);
		emCmp[1] = new EmployeCmp("G", 22);
		emCmp[2] = new EmployeCmp("H", 2);
		emCmp[3] = new EmployeCmp("I", 2);
		emCmp[4] = new EmployeCmp("J", 1);

		Pair pCmp = Pair.minMax(emCmp);
		System.out.println(pCmp);
		
	}
}


