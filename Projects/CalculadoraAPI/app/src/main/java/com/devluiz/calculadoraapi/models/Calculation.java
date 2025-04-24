package com.devluiz.calculadoraapi.models;

import com.google.gson.annotations.Expose;
import com.google.gson.annotations.SerializedName;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Calculation {

    // Uso de Expose para evitar que o id seja enviado na crição
    // mas permite que seja recebido
    @Expose(serialize = false, deserialize = true)
    private int id;

    // Uso de SearelizedName para colocar o nome correto no json da requisição,
    // mantendo o código com padrão de nomenclatura em inglês
    @SerializedName("valorA")
    private double valueA;

    @SerializedName("valorB")
    private double valueB;

    @SerializedName("resultado")
    private double result;

    @SerializedName("operacao")
    private String operation;

    @SerializedName("dataCalculo")
    private LocalDateTime date;

    public Calculation(double valueA, double valueB, double result, String operation) {
        this.valueA = valueA;
        this.valueB = valueB;
        this.result = result;
        this.operation = operation;
        this.date = LocalDateTime.now();
    }

    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }

    public double getValueA() {
        return valueA;
    }
    public void setValueA(double valueA) {
        this.valueA = valueA;
    }

    public double getValueB() {
        return valueB;
    }
    public void setValueB(double valueB) {
        this.valueB = valueB;
    }

    public double getResult() {
        return result;
    }
    public void setResult(double result) {
        this.result = result;
    }

    public String getOperation() {
        return operation;
    }
    public void setOperation(String operation) {
        this.operation = operation;
    }

    public LocalDateTime getDate() {
        return date;
    }
    public void setDate(LocalDateTime date) {
        this.date = date;
    }

    public String getFormattedDate() {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm");
        return date.format(formatter);
    }
}
