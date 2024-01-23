// Blueprint for all GameState subclasses.
// Has a reference to the GameStateManager
// along with the four methods that must
// be overridden.

package com.neet.DiamondHunter.GameState;

import java.awt.Graphics2D;

import com.neet.DiamondHunter.Manager.GameStateManager;

public abstract class GameState {
	
	protected GameStateManager gsm;
	
	public GameState(GameStateManager gsm) {
		this.gsm = gsm;
	}
	
	public abstract void init();
	public abstract void update();
	public abstract void draw(Graphics2D g);
	public abstract void handleInput();
	
}
