import java.awt.EventQueue;
import java.io.*;
import java.net.*;
import java.util.StringTokenizer;

import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JTextArea;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;


public class Client {

	private JFrame frame;
	private JTextField serverip;
	private JTextField login;
	private JTextField msg;
	String user,ser_ip;
	static Socket s=null;
	DataOutputStream dout;
    DataInputStream din;
    private JTextField status;
    final JTextArea hist = new JTextArea();
	
    
    public void recieve_msg() 
	{
		while(true){
			
			String msg=null;
			int flag=0;
			
			try {
				msg=din.readUTF();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				//e.printStackTrace();
			}
			if(msg.length()>=3)
			{
				//System.out.println("msg="+msg);
				//System.out.println("length of msg="+msg.length());
			char[] val=msg.toCharArray();
			//System.out.println(msg);
			
			if(val[0]=='!' && val[1]=='@' && val[2]=='#')
			{
				flag=1;
				//System.out.println("here1");
				status.setText("Username not available");
				
			}

			else
			{
			//System.out.println("here2");
			flag=1;
			
			hist.append(msg + "\n");
			}
			}
			
			if(flag==0 && msg.length()>0)
			{
				//System.out.println("here1");
				//System.out.println("here3");
				hist.append(msg + "\n");
			}
			
		
		
		}
	}

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Client window = new Client();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public Client() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame("Client");
		frame.setBounds(100, 100, 562, 380);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		serverip = new JTextField();
		serverip.setBounds(157, 28, 174, 39);
		frame.getContentPane().add(serverip);
		serverip.setColumns(10);
		
		JLabel lblServerIpAddress = new JLabel("Server IP Address");
		lblServerIpAddress.setBounds(12, 40, 127, 15);
		frame.getContentPane().add(lblServerIpAddress);
		
		JButton btnSubmit = new JButton("Submit");
		btnSubmit.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				
				user=login.getText();
				
				ser_ip=serverip.getText();
				int flag=0;
				
				try {
					s=new Socket(ser_ip,5217);
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					status.setText("Server not available");
					flag=1;
					//e1.printStackTrace();
				}
				
			/*	if(flag==0)
				{
				status.setText("CONNECTED");
				}*/
				
				try {
					din=new DataInputStream(s.getInputStream());
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					//e1.printStackTrace();
				} 
		        try {
					dout=new DataOutputStream(s.getOutputStream());
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					//e1.printStackTrace();
				}        
		        try {
					dout.writeUTF(user);
				} catch (IOException e1) {
					// TODO Auto-generated catch block
				//	e1.printStackTrace();
				}
		        
		        if(flag==0)
				{
				status.setText("CONNECTED");
				}
		        
		        Thread trd = new Thread(){
					
					public void run()
					{
						recieve_msg();
					}	
				};
				
				trd.start();
				
			}
			
			
			
			
		});
		btnSubmit.setBounds(184, 138, 117, 25);
		frame.getContentPane().add(btnSubmit);
		
		login = new JTextField();
		login.setColumns(10);
		login.setBounds(157, 82, 174, 39);
		frame.getContentPane().add(login);
		
		JLabel lblLoginName = new JLabel("Login Name");
		lblLoginName.setBounds(12, 94, 111, 15);
		frame.getContentPane().add(lblLoginName);
		
		msg = new JTextField();
		msg.setBounds(43, 195, 152, 75);
		frame.getContentPane().add(msg);
		msg.setColumns(10);
		
		JButton btnSend = new JButton("Send");
		btnSend.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				String mymsg=null;
				mymsg=msg.getText();
				String tochat=user;
				try {
					dout.writeUTF(tochat + " " + "DATA" + " " + mymsg);
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				//hist.append("Reply" + ":" + mymsg + "\n");
				
				msg.setText("");
				}
				
				
			
		});
		btnSend.setBounds(64, 282, 117, 25);
		frame.getContentPane().add(btnSend);
		
		
		hist.setBounds(297, 213, 187, 57);
		JScrollPane sp=new JScrollPane(hist);
		sp.setBounds(297,213,187,57);
		frame.getContentPane().add(sp);
		
		JLabel lblReply = new JLabel("Reply");
		lblReply.setBounds(365, 186, 70, 15);
		frame.getContentPane().add(lblReply);
		
		status = new JTextField();
		status.setBounds(365, 92, 146, 29);
		frame.getContentPane().add(status);
		status.setColumns(10);
		
		JButton btnClose = new JButton("Close");
		btnClose.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				
				try {
					dout.writeUTF(user+ " LOGOUT");
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				try {
					s.close();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				
				System.exit(0);
			}
		});
		btnClose.setBounds(365, 282, 117, 25);
		frame.getContentPane().add(btnClose);
	}
}
