package Vista;

import Controlador.ControladorInitStartGUI;
import Controlador.Validate.Validator;
import java.awt.event.KeyEvent;
import javax.swing.JOptionPane;

public class InitStartGUI extends javax.swing.JFrame {

    private ControladorInitStartGUI controlGUI;
    private String txtOutputMsg = "";

    public InitStartGUI() {
        initComponents();
        this.setLocationRelativeTo(null);
        this.setResizable(false);
        this.setTitle("CodeForm");

        controlGUI = new ControladorInitStartGUI();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        panelInput = new javax.swing.JPanel();
        panelContainer = new javax.swing.JPanel();
        panelContainerCode = new javax.swing.JPanel();
        lblCodigo = new javax.swing.JLabel();
        txtCodigo = new javax.swing.JTextField();
        panelMainBtn = new javax.swing.JPanel();
        btnSubmit = new javax.swing.JButton();
        btnLimpiar = new javax.swing.JButton();
        txtOutput = new javax.swing.JScrollPane();
        txtOutputText = new javax.swing.JTextArea();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        lblCodigo.setText("Código:");

        txtCodigo.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                txtCodigoKeyPressed(evt);
            }
            public void keyTyped(java.awt.event.KeyEvent evt) {
                txtCodigoKeyTyped(evt);
            }
        });

        javax.swing.GroupLayout panelContainerCodeLayout = new javax.swing.GroupLayout(panelContainerCode);
        panelContainerCode.setLayout(panelContainerCodeLayout);
        panelContainerCodeLayout.setHorizontalGroup(
            panelContainerCodeLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelContainerCodeLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(lblCodigo, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(txtCodigo)
                .addContainerGap())
        );
        panelContainerCodeLayout.setVerticalGroup(
            panelContainerCodeLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelContainerCodeLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(panelContainerCodeLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(lblCodigo, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(txtCodigo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(26, Short.MAX_VALUE))
        );

        btnSubmit.setText("Enviar");
        btnSubmit.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnSubmitActionPerformed(evt);
            }
        });

        btnLimpiar.setText("Limpiar");
        btnLimpiar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnLimpiarActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout panelMainBtnLayout = new javax.swing.GroupLayout(panelMainBtn);
        panelMainBtn.setLayout(panelMainBtnLayout);
        panelMainBtnLayout.setHorizontalGroup(
            panelMainBtnLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelMainBtnLayout.createSequentialGroup()
                .addGap(24, 24, 24)
                .addComponent(btnSubmit)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 52, Short.MAX_VALUE)
                .addComponent(btnLimpiar)
                .addGap(22, 22, 22))
        );
        panelMainBtnLayout.setVerticalGroup(
            panelMainBtnLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelMainBtnLayout.createSequentialGroup()
                .addGap(23, 23, 23)
                .addGroup(panelMainBtnLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnSubmit)
                    .addComponent(btnLimpiar))
                .addContainerGap(23, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout panelContainerLayout = new javax.swing.GroupLayout(panelContainer);
        panelContainer.setLayout(panelContainerLayout);
        panelContainerLayout.setHorizontalGroup(
            panelContainerLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelContainerLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(panelContainerLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addComponent(panelContainerCode, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(panelMainBtn, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(19, Short.MAX_VALUE))
        );
        panelContainerLayout.setVerticalGroup(
            panelContainerLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelContainerLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(panelContainerCode, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(panelMainBtn, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout panelInputLayout = new javax.swing.GroupLayout(panelInput);
        panelInput.setLayout(panelInputLayout);
        panelInputLayout.setHorizontalGroup(
            panelInputLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelInputLayout.createSequentialGroup()
                .addComponent(panelContainer, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 10, Short.MAX_VALUE))
        );
        panelInputLayout.setVerticalGroup(
            panelInputLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, panelInputLayout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(panelContainer, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );

        txtOutputText.setEditable(false);
        txtOutputText.setColumns(20);
        txtOutputText.setRows(5);
        txtOutput.setViewportView(txtOutputText);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(panelInput, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(txtOutput, javax.swing.GroupLayout.PREFERRED_SIZE, 380, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(txtOutput, javax.swing.GroupLayout.PREFERRED_SIZE, 295, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(69, 69, 69)
                        .addComponent(panelInput, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(36, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void txtCodigoKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_txtCodigoKeyPressed

    }//GEN-LAST:event_txtCodigoKeyPressed

    private void txtCodigoKeyTyped(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_txtCodigoKeyTyped
        if (!(evt.getKeyChar() >= '0' && evt.getKeyChar() <= '9')) {
            evt.consume();
        }
    }//GEN-LAST:event_txtCodigoKeyTyped

    private void btnSubmitActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnSubmitActionPerformed
        int codigo = 0;
        boolean inputNumberFlag = false;
        try {
            codigo = Integer.parseInt(txtCodigo.getText());
            inputNumberFlag = controlGUI.validateInputs(codigo);
            if (!inputNumberFlag) {
                if (!controlGUI.validateCodeNumber(codigo)) {
                    this.cleanAll();
                    controlGUI.inputDataCode(codigo);
                    this.inputDataDigits(controlGUI);
                } else {
                    JOptionPane.showMessageDialog(null, "Número fuera de rango de código");
                }
            } else {
                JOptionPane.showMessageDialog(null, "Ingreso Inválido");
            }
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(null, "Ingreso Inválido : " + ex);
        }
    }//GEN-LAST:event_btnSubmitActionPerformed

    private void btnLimpiarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnLimpiarActionPerformed
        this.cleanAll();
    }//GEN-LAST:event_btnLimpiarActionPerformed

    private void inputDataDigits(ControladorInitStartGUI controlGUI) {
        boolean inputFlag = true;
        int inputUserDigit = 0;
        String msg = "";
        for (int i = 0; i < controlGUI.getDigitosIngresados().length; i++) {
            if (i % 2 == 0) {
                controlGUI.getDigitosIngresados()[i] = controlGUI.getMayorDigitoCodigo();
            } else {
                do {
                    inputFlag = false;
                    try {

                        do {
                            msg = "\nPosición :  " + (i + 1) + " |  Ingrese dígito : ";
                            String inData = JOptionPane.showInputDialog(null, msg);
                            inputUserDigit = Integer.parseInt(inData);
                        } while (inputUserDigit < -10 || inputUserDigit > 10);

                    } catch (Exception ex) {
                        inputFlag = true;
                        JOptionPane.showMessageDialog(null, "Ingreso Inválido");

                    }

                } while (inputFlag == true);

                controlGUI.getDigitosIngresados()[i] = inputUserDigit;
            }
        }

        this.showReport(controlGUI);
    }

    private void showReport(ControladorInitStartGUI controlGUI) {
        this.txtOutputMsg += "Número Ingresado : "+controlGUI.getCodigoBean().getCodigo()+"\n";
        this.txtOutputMsg += "Datos ingresados-Casillas Mayor Número";
        for (int i = 0; i < controlGUI.getDigitosIngresados().length; i++) {
            if (i % 2 == 0) {
                this.txtOutputMsg += "\nPosición: " + (i + 1) + " Mayor número Código : " + controlGUI.getDigitosIngresados()[i];
            } else {
                this.txtOutputMsg += "\nPosición: " + (i + 1) + " Número ingresado : " + controlGUI.getDigitosIngresados()[i];
            }

        }

        this.showResults(this.txtOutputMsg);
    }

    private void showResults(final String txtOutputData) {
        txtOutputText.setText(txtOutputData);
    }

    private void cleanCodeTxt() {
        this.txtOutputMsg = Validator.emptySpace;
        this.txtCodigo.setText(Validator.emptySpace);
    }

    private void cleanAll() {
        this.cleanCodeTxt();
        this.txtOutputText.setText(Validator.emptySpace);
    }

    public static void main(String args[]) {

        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new InitStartGUI().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnLimpiar;
    private javax.swing.JButton btnSubmit;
    private javax.swing.JLabel lblCodigo;
    private javax.swing.JPanel panelContainer;
    private javax.swing.JPanel panelContainerCode;
    private javax.swing.JPanel panelInput;
    private javax.swing.JPanel panelMainBtn;
    private javax.swing.JTextField txtCodigo;
    private javax.swing.JScrollPane txtOutput;
    private javax.swing.JTextArea txtOutputText;
    // End of variables declaration//GEN-END:variables
}
