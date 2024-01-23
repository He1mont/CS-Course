// Contains an array of current key state
// previous key state. A value of true
// means the key is pressed.

// The GamePanel KeyListener will update the array.
// All GameStates now have a handleInput() function
// in order to keep all keyboard input operations
// on the game thread rather than on the EDT to avoid
// problems.

package com.neet.DiamondHunter.Manager;

import java.awt.event.KeyEvent;

public class Keys {
	
	public static final int NUM_KEYS = 8;
	
	public static boolean keyState[] = new boolean[NUM_KEYS];
	public static boolean prevKeyState[] = new boolean[NUM_KEYS];
	
	public static int UP = 0;
	public static int LEFT = 1;
	public static int DOWN = 2;
	public static int RIGHT = 3;
	public static int SPACE = 4;
	public static int ENTER = 5;
	public static int ESCAPE = 6;
	public static int F1 = 7;
	
	public static void keySet(int i, boolean b) {
		if(i == KeyEvent.VK_UP) keyState[UP] = b;
		else if(i == KeyEvent.VK_LEFT) keyState[LEFT] = b;
		else if(i == KeyEvent.VK_DOWN) keyState[DOWN] = b;
		else if(i == KeyEvent.VK_RIGHT) keyState[RIGHT] = b;
		else if(i == KeyEvent.VK_SPACE) keyState[SPACE] = b;
		else if(i == KeyEvent.VK_ENTER) keyState[ENTER] = b;
		else if(i == KeyEvent.VK_ESCAPE) keyState[ESCAPE] = b;
		else if(i == KeyEvent.VK_F1) keyState[F1] = b;
	}
	
	public static void update() {
		for(int i = 0; i < NUM_KEYS; i++) {
			prevKeyState[i] = keyState[i];
		}
	}
	
	public static boolean isPressed(int i) {
		return keyState[i] && !prevKeyState[i];
	}
	
	public static boolean isDown(int i) {
		return keyState[i];
	}
	
	public static boolean anyKeyDown() {
		for(int i = 0; i < NUM_KEYS; i++) {
			if(keyState[i]) return true;
		}
		return false;
	}
	
	public static boolean anyKeyPress() {
		for(int i = 0; i < NUM_KEYS; i++) {
			if(keyState[i] && !prevKeyState[i]) return true;
		}
		return false;
	}
	
}
