package com.COMP2013;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class HelloWorldSwingGUIApp extends JFrame {
    public HelloWorldSwingGUIApp() {
        initUI();
    }

    private void initUI() {
        setSize(600, 600);
        setTitle("My first GUI in Java Swing. Hello World!");
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        JPanel pannel = new JPanel(new GridBagLayout());
        JButton button1 = new JButton("Exit Program");
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("How we will exit the program");
                System.exit(0);
            }
        });
        pannel.add(button1);
        this.add(pannel);
    }

    // main function
    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                new HelloWorldSwingGUIApp().setVisible(true);
            }
        });
    }

}
