import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class calculadoraGUI extends JFrame {
    private JTextField textField;
    private double resultado;
    private boolean novoNumero = true;

    public calculadoraGUI() {
        setTitle("Calculadora");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 400);
        setLocationRelativeTo(null);

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(4, 4));

        textField = new JTextField();
        textField.setFont(new Font("Tahoma", Font.BOLD, 50));
        textField.setHorizontalAlignment(JTextField.RIGHT);
        textField.setEditable(false);

        String[] botoes = {
            "7", "8", "9", "/",
            "4", "5", "6", "*",
            "1", "2", "3", "-",
            "0", ".", "=", "+"
        };

        for (String textoBotao : botoes) {
            JButton botao = new JButton(textoBotao);
            botao.setFont(new Font("Tahoma", Font.BOLD, 24));
            panel.add(botao);
            botao.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    onButtonClick(textoBotao);
                }
            });
        }

        add(textField, BorderLayout.NORTH);
        add(panel);

        setVisible(true);
    }

    private void onButtonClick(String textoBotao) {
        if (novoNumero) {
            textField.setText("");
            novoNumero = false;
        }

        if (textoBotao.equals("=")) {
            calcularResultado();
        } else {
            textField.setText(textField.getText() + textoBotao);
        }
    }

    private void calcularResultado() {
        try {
            String expressao = textField.getText();
            //resultado = IMPLEMENTAR OS PADRÕES DE PROJETO AQUI
            textField.setText(Double.toString(resultado));
            novoNumero = true;
        } catch (Exception ex) {
            textField.setText("Erro");
        }
    }

    public static void main(String[] args) {
        new calculadoraGUI();
    }
}