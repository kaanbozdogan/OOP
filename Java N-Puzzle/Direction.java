
public enum Direction {
	UP (0), DOWN (1), LEFT (2), RIGHT (3), NONE (4);
	
	public final int value;
	
	private Direction(int val){
		value = val;
	}
	
	public static Direction intToEnum(int val){
		
		for(Direction dir : values()){
		
			if( dir.value==val ) {
			
				return dir;
			}
		}
		return null;
	}
	
}
