package Vista;

import java.awt.Font;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;

public class ViewGUI extends javax.swing.JFrame {

    public ViewGUI() {
        initComponents();
        setResizable(false);
        setLocationRelativeTo(null);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        rbGroup1 = new javax.swing.ButtonGroup();
        sliderGUI = new javax.swing.JSlider();
        btnCommand1 = new javax.swing.JButton();
        btnCommand2 = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        tblGUI = new javax.swing.JTable();
        jScrollPane2 = new javax.swing.JScrollPane();
        txtArea1 = new javax.swing.JTextArea();
        jPanel1 = new javax.swing.JPanel();
        rbOption1 = new javax.swing.JRadioButton();
        rbOption2 = new javax.swing.JRadioButton();
        rbOption3 = new javax.swing.JRadioButton();
        rbOption4 = new javax.swing.JRadioButton();
        btnCommand3 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        sliderGUI.setMaximum(8);
        sliderGUI.setValue(4);
        sliderGUI.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                sliderGUIStateChanged(evt);
            }
        });

        btnCommand1.setText("Soy Un Botón");
        btnCommand1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCommand1ActionPerformed(evt);
            }
        });

        btnCommand2.setText("Input");
        btnCommand2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCommand2ActionPerformed(evt);
            }
        });

        tblGUI.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Col 1", "Col 2", "Col 3", "Col 4"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }
        });
        tblGUI.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                tblGUIMouseClicked(evt);
            }
        });
        jScrollPane1.setViewportView(tblGUI);
        if (tblGUI.getColumnModel().getColumnCount() > 0) {
            tblGUI.getColumnModel().getColumn(0).setResizable(false);
            tblGUI.getColumnModel().getColumn(1).setResizable(false);
        }

        txtArea1.setColumns(20);
        txtArea1.setRows(5);
        jScrollPane2.setViewportView(txtArea1);

        rbGroup1.add(rbOption1);
        rbOption1.setText("Manzana");
        rbOption1.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                rbOption1ItemStateChanged(evt);
            }
        });

        rbGroup1.add(rbOption2);
        rbOption2.setText("Naranja");
        rbOption2.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                rbOption2ItemStateChanged(evt);
            }
        });

        rbGroup1.add(rbOption3);
        rbOption3.setText("Banana");
        rbOption3.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                rbOption3ItemStateChanged(evt);
            }
        });

        rbGroup1.add(rbOption4);
        rbOption4.setText("Pera");
        rbOption4.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                rbOption4ItemStateChanged(evt);
            }
        });

        btnCommand3.setText("Elige una Fruta");
        btnCommand3.setEnabled(false);
        btnCommand3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCommand3ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(25, 25, 25)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(rbOption4)
                            .addComponent(rbOption1))
                        .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(rbOption3)
                            .addComponent(rbOption2))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 106, Short.MAX_VALUE)
                        .addComponent(btnCommand3, javax.swing.GroupLayout.PREFERRED_SIZE, 129, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(34, 34, 34))))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(27, 27, 27)
                .addComponent(rbOption1)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(rbOption2)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(rbOption3))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(15, 15, 15)
                        .addComponent(btnCommand3)))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(rbOption4)
                .addContainerGap(32, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(43, 43, 43)
                        .addComponent(btnCommand2, javax.swing.GroupLayout.PREFERRED_SIZE, 177, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(59, 59, 59)
                        .addComponent(btnCommand1, javax.swing.GroupLayout.PREFERRED_SIZE, 177, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(126, 126, 126)
                        .addComponent(sliderGUI, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(25, 25, 25)
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 408, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 72, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jScrollPane2)
                    .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(27, 27, 27))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(43, 43, 43)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 207, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 196, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(34, 34, 34)
                        .addComponent(sliderGUI, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(48, 48, 48)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(btnCommand2, javax.swing.GroupLayout.PREFERRED_SIZE, 39, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(btnCommand1, javax.swing.GroupLayout.PREFERRED_SIZE, 39, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(18, 18, 18)
                        .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(27, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void sliderGUIStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_sliderGUIStateChanged
        txtArea1.setFont(new Font("Arial", Font.PLAIN, sliderGUI.getValue() + 20));
        btnCommand1.setFont(new Font("Arial", Font.PLAIN, sliderGUI.getValue() + 10));
    }//GEN-LAST:event_sliderGUIStateChanged

    private void btnCommand2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCommand2ActionPerformed

        tblGUI.setModel(new DefaultTableModel(sliderGUI.getValue(), 4));
        btnCommand1.setText("Hola, soy un botón");
        txtArea1.setText("");
        rbGroup1.clearSelection();
        btnCommand3.setEnabled(false);
        txtArea1.setFont(new Font("Arial", Font.PLAIN, sliderGUI.getValue() + 10));

    }//GEN-LAST:event_btnCommand2ActionPerformed

    private void tblGUIMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_tblGUIMouseClicked
        try {
            DefaultTableModel model = (DefaultTableModel) tblGUI.getModel();
            int selectedRow = tblGUI.getSelectedRow();

            String str = model.getValueAt(selectedRow, 0).toString() + " " + model.getValueAt(selectedRow, 1).toString() + " "
                    + model.getValueAt(selectedRow, 2).toString() + " " + model.getValueAt(selectedRow, 3).toString();

            btnCommand1.setText(str);
            txtArea1.setText(str);

        } catch (Exception ex) {

        }

    }//GEN-LAST:event_tblGUIMouseClicked

    private void btnCommand1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCommand1ActionPerformed
        JOptionPane.showMessageDialog(null, txtArea1.getText());
        tblGUI.setModel(new DefaultTableModel(0, 4));
        txtArea1.setText("");
        txtArea1.setFont(new Font("Arial", Font.PLAIN, sliderGUI.getValue() + 10));
        rbGroup1.clearSelection();
        btnCommand3.setEnabled(false);
    }//GEN-LAST:event_btnCommand1ActionPerformed

    private void btnCommand3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCommand3ActionPerformed
        String msg = "\n Hola, soy una ";
        if (rbOption1.isSelected()) {
            msg += "manzana";
        } else if (rbOption2.isSelected()) {
            msg += "naranja";
        } else if (rbOption3.isSelected()) {
            msg += "banana";
        } else {
            msg += "pera";
        }

        txtArea1.setText(msg);
    }//GEN-LAST:event_btnCommand3ActionPerformed

    private void rbOption1ItemStateChanged(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_rbOption1ItemStateChanged
        if (evt.getStateChange() == java.awt.event.ItemEvent.SELECTED) {
            btnCommand3.setEnabled(true);
        }
    }//GEN-LAST:event_rbOption1ItemStateChanged

    private void rbOption2ItemStateChanged(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_rbOption2ItemStateChanged
        if (evt.getStateChange() == java.awt.event.ItemEvent.SELECTED) {
            btnCommand3.setEnabled(true);
        }
    }//GEN-LAST:event_rbOption2ItemStateChanged

    private void rbOption3ItemStateChanged(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_rbOption3ItemStateChanged
        if (evt.getStateChange() == java.awt.event.ItemEvent.SELECTED) {
            btnCommand3.setEnabled(true);
        }
    }//GEN-LAST:event_rbOption3ItemStateChanged

    private void rbOption4ItemStateChanged(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_rbOption4ItemStateChanged
        if (evt.getStateChange() == java.awt.event.ItemEvent.SELECTED) {
            btnCommand3.setEnabled(true);
        }
    }//GEN-LAST:event_rbOption4ItemStateChanged

    public static void main(String args[]) {

        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new ViewGUI().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnCommand1;
    private javax.swing.JButton btnCommand2;
    private javax.swing.JButton btnCommand3;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.ButtonGroup rbGroup1;
    private javax.swing.JRadioButton rbOption1;
    private javax.swing.JRadioButton rbOption2;
    private javax.swing.JRadioButton rbOption3;
    private javax.swing.JRadioButton rbOption4;
    private javax.swing.JSlider sliderGUI;
    private javax.swing.JTable tblGUI;
    private javax.swing.JTextArea txtArea1;
    // End of variables declaration//GEN-END:variables
}
