	public enum Notifications {
		  ERROR(0, "A error has occured."),
		  MACHINE_READY(1, "Vending Machine is Ready For Order."),
		  ITEM_OUT_OF_STOCK(2, "Item Out Of Stock."),
		  INSERT_COINS(3, "To Order The Item Please Insert Coins."),
		  PURCHACE_SUCCES(4, "Enjoy You Drink: "),
		  NEW_BALANCE(5, "Balance: "),
		  CHANGE(6, "Change: "),
		  PLEASE_WAIT(7, "Please Wait Your Item Is On The Way... "),
		  MORE_COINS_NEEDED(8, "Low Balance To Make Purchase Missing More: ");
		
		  private final int code;
		  private final String description;

		  private Notifications(int code, String description) {
		    this.code = code;
		    this.description = description;
		  }

		  public String getDescription() {
		     return description;
		  }

		  public int getCode() {
		     return code;
		  }

		  @Override
		  public String toString() {
		    return "("+ code + ")" + ": " + description;
		  }
	}

