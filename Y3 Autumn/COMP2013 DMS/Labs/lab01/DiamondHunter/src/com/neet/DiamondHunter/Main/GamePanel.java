// The GamePanel is the drawing canvas.
// It contains the game loop which
// keeps the game moving forward.
// This class is also the one that grabs key events.

package com.neet.DiamondHunter.Main;

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;

import javax.swing.JPanel;

import com.neet.DiamondHunter.Manager.GameStateManager;
import com.neet.DiamondHunter.Manager.Keys;

@SuppressWarnings("serial")
public class GamePanel extends JPanel implements Runnable, KeyListener {
	
	// dimensions
	// HEIGHT is the playing area size
	// HEIGHT2 includes the bottom window
	public static final int WIDTH = 128;
	public static final int HEIGHT = 128;
	public static final int HEIGHT2 = HEIGHT + 16;
	public static final int SCALE = 3;
	
	// game loop stuff
	private Thread thread;
	private boolean running;
	private final int FPS = 30;
	private final int TARGET_TIME = 1000 / FPS;
	
	// drawing stuff
	private BufferedImage image;
	private Graphics2D g;
	
	// game state manager
	private GameStateManager gsm;
	
	// constructor
	public GamePanel() {
		setPreferredSize(new Dimension(WIDTH * SCALE, HEIGHT2 * SCALE));
		setFocusable(true);
		requestFocus();
	}
	
	// ready to display
	public void addNotify() {
		super.addNotify();
		if(thread == null) {
			addKeyListener(this);
			thread = new Thread(this);
			thread.start();
		}
	}
	
	// run new thread
	public void run() {
		
		init();
		
		long start;
		long elapsed;
		long wait;
		
		// game loop
		while(running) {
			
			start = System.nanoTime();
			
			update();
			draw();
			drawToScreen();
			
			elapsed = System.nanoTime() - start;
			
			wait = TARGET_TIME - elapsed / 1000000;
			if(wait < 0) wait = TARGET_TIME;
			
			try {
				Thread.sleep(wait);
			}
			catch(Exception e) {
				e.printStackTrace();
			}
			
		}
		
	}
	
	// initializes fields
	private void init() {
		running = true;
		image = new BufferedImage(WIDTH, HEIGHT2, 1);
		g = (Graphics2D) image.getGraphics();
		gsm = new GameStateManager();
	}
	
	// updates game
	private void update() {
		gsm.update();
		Keys.update();
	}
	
	// draws game
	private void draw() {
		gsm.draw(g);
	}
	
	// copy buffer to screen
	private void drawToScreen() {
		Graphics g2 = getGraphics();
		g2.drawImage(image, 0, 0, WIDTH * SCALE, HEIGHT2 * SCALE, null);
		g2.dispose();
	}
	
	// key event
	public void keyTyped(KeyEvent key) {}
	public void keyPressed(KeyEvent key) {
		Keys.keySet(key.getKeyCode(), true);
	}
	public void keyReleased(KeyEvent key) {
		Keys.keySet(key.getKeyCode(), false);
	}
	
}
