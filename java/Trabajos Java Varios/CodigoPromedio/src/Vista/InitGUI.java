package Vista;

import Controlador.ControllerInitGUI;
import Controlador.Validate.Validator;
import java.awt.event.KeyEvent;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

public class InitGUI extends javax.swing.JFrame {

    ControllerInitGUI controlGUI;
    private String txtOutputMsg = "";

    public InitGUI() {
        initComponents();
        this.setLocationRelativeTo(null);
        this.setResizable(false);
        this.setTitle("CodeForm");
        controlGUI = new ControllerInitGUI();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        panelContainerCode1 = new javax.swing.JPanel();
        lblCodigo1 = new javax.swing.JLabel();
        txtCodigo1 = new javax.swing.JTextField();
        panelInput = new javax.swing.JPanel();
        panelContainerCode = new javax.swing.JPanel();
        lblCodigo = new javax.swing.JLabel();
        txtCodigo = new javax.swing.JTextField();
        panelContainerApellido = new javax.swing.JPanel();
        lblApellido = new javax.swing.JLabel();
        txtApellido = new javax.swing.JTextField();
        panelContainerNombre = new javax.swing.JPanel();
        lblNombre = new javax.swing.JLabel();
        txtNombre = new javax.swing.JTextField();
        btnSubmit = new javax.swing.JButton();
        btnLimpiar = new javax.swing.JButton();
        panelOutput = new javax.swing.JPanel();
        txtOutput = new javax.swing.JScrollPane();
        txtOutputText = new javax.swing.JTextArea();

        lblCodigo1.setText("Código:");

        javax.swing.GroupLayout panelContainerCode1Layout = new javax.swing.GroupLayout(panelContainerCode1);
        panelContainerCode1.setLayout(panelContainerCode1Layout);
        panelContainerCode1Layout.setHorizontalGroup(
            panelContainerCode1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelContainerCode1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(lblCodigo1, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(txtCodigo1, javax.swing.GroupLayout.DEFAULT_SIZE, 168, Short.MAX_VALUE)
                .addContainerGap())
        );
        panelContainerCode1Layout.setVerticalGroup(
            panelContainerCode1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelContainerCode1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(panelContainerCode1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(lblCodigo1, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(txtCodigo1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(22, Short.MAX_VALUE))
        );

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
                .addContainerGap(22, Short.MAX_VALUE))
        );

        lblApellido.setText("Apellido:");

        txtApellido.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                txtApellidoKeyPressed(evt);
            }
            public void keyTyped(java.awt.event.KeyEvent evt) {
                txtApellidoKeyTyped(evt);
            }
        });

        javax.swing.GroupLayout panelContainerApellidoLayout = new javax.swing.GroupLayout(panelContainerApellido);
        panelContainerApellido.setLayout(panelContainerApellidoLayout);
        panelContainerApellidoLayout.setHorizontalGroup(
            panelContainerApellidoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelContainerApellidoLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(lblApellido, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(txtApellido, javax.swing.GroupLayout.DEFAULT_SIZE, 188, Short.MAX_VALUE)
                .addContainerGap())
        );
        panelContainerApellidoLayout.setVerticalGroup(
            panelContainerApellidoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelContainerApellidoLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(panelContainerApellidoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(lblApellido, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(txtApellido, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(22, Short.MAX_VALUE))
        );

        lblNombre.setText("Nombre:");

        txtNombre.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                txtNombreKeyPressed(evt);
            }
            public void keyTyped(java.awt.event.KeyEvent evt) {
                txtNombreKeyTyped(evt);
            }
        });

        javax.swing.GroupLayout panelContainerNombreLayout = new javax.swing.GroupLayout(panelContainerNombre);
        panelContainerNombre.setLayout(panelContainerNombreLayout);
        panelContainerNombreLayout.setHorizontalGroup(
            panelContainerNombreLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelContainerNombreLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(lblNombre, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(txtNombre, javax.swing.GroupLayout.DEFAULT_SIZE, 188, Short.MAX_VALUE)
                .addContainerGap())
        );
        panelContainerNombreLayout.setVerticalGroup(
            panelContainerNombreLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelContainerNombreLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(panelContainerNombreLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(lblNombre, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(txtNombre, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(22, Short.MAX_VALUE))
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

        javax.swing.GroupLayout panelInputLayout = new javax.swing.GroupLayout(panelInput);
        panelInput.setLayout(panelInputLayout);
        panelInputLayout.setHorizontalGroup(
            panelInputLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelInputLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(panelInputLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(panelContainerCode, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(panelContainerApellido, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
            .addGroup(panelInputLayout.createSequentialGroup()
                .addGap(27, 27, 27)
                .addComponent(btnSubmit)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(btnLimpiar)
                .addGap(36, 36, 36))
            .addGroup(panelInputLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, panelInputLayout.createSequentialGroup()
                    .addContainerGap()
                    .addComponent(panelContainerNombre, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addContainerGap()))
        );
        panelInputLayout.setVerticalGroup(
            panelInputLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(panelInputLayout.createSequentialGroup()
                .addGap(73, 73, 73)
                .addComponent(panelContainerApellido, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(panelContainerCode, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(panelInputLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnSubmit)
                    .addComponent(btnLimpiar))
                .addContainerGap(53, Short.MAX_VALUE))
            .addGroup(panelInputLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(panelInputLayout.createSequentialGroup()
                    .addGap(10, 10, 10)
                    .addComponent(panelContainerNombre, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addContainerGap(224, Short.MAX_VALUE)))
        );

        txtOutputText.setEditable(false);
        txtOutputText.setColumns(20);
        txtOutputText.setRows(5);
        txtOutput.setViewportView(txtOutputText);

        javax.swing.GroupLayout panelOutputLayout = new javax.swing.GroupLayout(panelOutput);
        panelOutput.setLayout(panelOutputLayout);
        panelOutputLayout.setHorizontalGroup(
            panelOutputLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(txtOutput, javax.swing.GroupLayout.DEFAULT_SIZE, 300, Short.MAX_VALUE)
        );
        panelOutputLayout.setVerticalGroup(
            panelOutputLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(txtOutput, javax.swing.GroupLayout.Alignment.TRAILING)
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(panelInput, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 16, Short.MAX_VALUE)
                .addComponent(panelOutput, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(panelInput, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(panelOutput, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void txtNombreKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_txtNombreKeyPressed
    }//GEN-LAST:event_txtNombreKeyPressed

    private void txtApellidoKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_txtApellidoKeyPressed

    }//GEN-LAST:event_txtApellidoKeyPressed

    private void txtCodigoKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_txtCodigoKeyPressed

    }//GEN-LAST:event_txtCodigoKeyPressed

    private void txtNombreKeyTyped(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_txtNombreKeyTyped
        char character = evt.getKeyChar();
        int code = evt.getKeyCode();
        if (!Character.isLetter(character) && code != KeyEvent.VK_BACK_SPACE) {
            evt.consume();
        }
    }//GEN-LAST:event_txtNombreKeyTyped

    private void txtApellidoKeyTyped(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_txtApellidoKeyTyped
        char character = evt.getKeyChar();
        int code = evt.getKeyCode();
        if (!Character.isLetter(character) && code != KeyEvent.VK_BACK_SPACE) {
            evt.consume();
        }
    }//GEN-LAST:event_txtApellidoKeyTyped

    private void txtCodigoKeyTyped(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_txtCodigoKeyTyped
        if (!(evt.getKeyChar() >= '0' && evt.getKeyChar() <= '9')) {
            evt.consume();
        } 
    }//GEN-LAST:event_txtCodigoKeyTyped

    private void btnSubmitActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnSubmitActionPerformed
        String name = "", lastName = "";
        int codigo = 0;
        boolean inputFlag = false;
        boolean inputNumberFlag = false;
        try {
            name = txtNombre.getText();
            lastName = txtApellido.getText();
            codigo = Integer.parseInt(txtCodigo.getText());
            inputFlag = controlGUI.validateInputs(name, lastName, codigo);
            if (!inputFlag) {
                if (!controlGUI.validateCodeNumber(codigo)) {
                    this.cleanOutputTxt();
                    controlGUI.setData(name, lastName, codigo);
                    this.txtOutputMsg += "\nPromedio Dígitos: " + controlGUI.getPromedio();
                    this.txtOutputMsg += "\nÚltimo Dígito: " + controlGUI.getUltimoDigitoCodigo();
                    this.txtOutputMsg += "\n_______________________________________";
                    if (controlGUI.getPromedio() < 3.55 && controlGUI.getUltimoDigitoCodigo() > 5) {
                        this.txtOutputMsg += "\nPromedio Dígitos: " + controlGUI.getPromedio();
                        this.txtOutputMsg += "\nApellidos Estudiante: " + controlGUI.getStudent().getApellido();
                    } else {
                        this.txtOutputMsg += "\nNombre Estudiante: " + controlGUI.getStudent().getNombre()
                                + " " + controlGUI.getStudent().getApellido();
                    }
                    this.cleanTxtFields();
                } else {
                    this.showMsg("Ingrese código de estudiante en rango correcto ");
                }

                this.showReport(this.txtOutputMsg);
            } else {
                this.showMsg("Ingrese datos válidos");
            }

        } catch (Exception ex) {
            this.showMsg("Error Ingreso de datos: " + ex);
        }
    }//GEN-LAST:event_btnSubmitActionPerformed

    private void btnLimpiarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnLimpiarActionPerformed
        this.cleanAll();
    }//GEN-LAST:event_btnLimpiarActionPerformed

    private void showReport(String report) {
        this.txtOutputText.setText(report);
    }

    private void showMsg(String msg) {
        JOptionPane.showMessageDialog(null, msg);
    }

    private void cleanTxtFields() {
        txtNombre.setText(Validator.emptySpace);
        txtApellido.setText(Validator.emptySpace);
        txtCodigo.setText(Validator.emptySpace);
    }

    private void cleanOutputTxt() {
        txtOutputText.setText(Validator.emptySpace);
        this.txtOutputMsg = Validator.emptySpace;
    }

    private void cleanAll() {
        this.cleanTxtFields();
        this.cleanOutputTxt();
    }

    public static void main(String args[]) {

        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new InitGUI().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnLimpiar;
    private javax.swing.JButton btnSubmit;
    private javax.swing.JLabel lblApellido;
    private javax.swing.JLabel lblCodigo;
    private javax.swing.JLabel lblCodigo1;
    private javax.swing.JLabel lblNombre;
    private javax.swing.JPanel panelContainerApellido;
    private javax.swing.JPanel panelContainerCode;
    private javax.swing.JPanel panelContainerCode1;
    private javax.swing.JPanel panelContainerNombre;
    private javax.swing.JPanel panelInput;
    private javax.swing.JPanel panelOutput;
    private javax.swing.JTextField txtApellido;
    private javax.swing.JTextField txtCodigo;
    private javax.swing.JTextField txtCodigo1;
    private javax.swing.JTextField txtNombre;
    private javax.swing.JScrollPane txtOutput;
    private javax.swing.JTextArea txtOutputText;
    // End of variables declaration//GEN-END:variables
}
