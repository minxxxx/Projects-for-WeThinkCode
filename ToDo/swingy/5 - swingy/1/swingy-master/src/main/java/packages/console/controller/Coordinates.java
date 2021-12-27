package packages.console.controller;


public class Coordinates {
	private int x, y;

	public Coordinates(int x, int y) {
		if (x < 0){
			this.x = 0;
		}else{
			this.x = x;
		}
		if (y < 0){
			this.y = 0;
		}else{
			this.y = y;
		}
	}

	public void advance(int direction) {
		if (direction == 1)
			x -= 1;
		else if (direction == 2)
			y += 1;
		else if (direction == 3)
			y -= 1;
		else if (direction == 4)
			x += 1;
	}

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}

	public void setX(int x)
	{
		this.x = x;
	}

	public void setY(int y)
	{
		this.y = y;
	}

	public boolean Isequals(Coordinates other) {
		return (this.y == other.y && this.x == other.x);
	}

	public static int getPositionMax(int pos, int max){
		if (pos <= max){
			return (pos);
		}
		return (max);
	}
}