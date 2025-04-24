package com.devluiz.calculadoraapi.controllers;

import androidx.annotation.NonNull;

import com.devluiz.calculadoraapi.interfaces.ApiCallback;
import com.devluiz.calculadoraapi.models.Calculation;
import com.devluiz.calculadoraapi.network.CalculationApi;

import java.util.List;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class CalculationController {
    private final CalculationApi apiCalculation = CalculationApi.create();
    private final String API_KEY = "CHAVE_DA_API";

    public void calculateAndCreate(double a, double b, String op, ApiCallback<Integer> callback) {
        if (op == null) {
            callback.onError("O operador não pode ser nulo");
            return;
        }

        double result;
        switch (op) {
            case "+": result = a + b; break;
            case "-": result = a - b; break;
            case "*": result = a * b; break;
            case "/":
                if (b == 0) {
                    callback.onError("Não é possível dividir por 0");
                    return;
                }
                result = a / b; break;
            default:
                callback.onError("Operador inválido: " + op);
                return;
        }
        // Mesmo com entrada controlada de operadores por botão,
        // o default gera uma garantia maior de integridade dos dados

        Calculation calculation = new Calculation(a, b, result, op);
        create(calculation, callback);
    }

    private void create(Calculation calculation, ApiCallback<Integer> callback) {
        Call<Integer> call = apiCalculation.post(API_KEY, calculation);
        call.enqueue(new Callback<Integer>() {

            @Override
            public void onResponse(@NonNull Call<Integer> call, @NonNull Response<Integer> response) {
                if (response.isSuccessful() && response.body() != null)
                    callback.onSuccess(response.body());
                else
                    callback.onError("Erro ao enviar cálculo: " + response.code());
            }

            @Override
            public void onFailure(@NonNull Call<Integer> call, @NonNull Throwable t) {
                callback.onError("Falha na API: " + t.getMessage());
            }
        });
    }

    public void getAll(ApiCallback<List<Calculation>> callback) {
        Call<List<Calculation>> call = apiCalculation.get(API_KEY);
        call.enqueue(new Callback<List<Calculation>>() {

            @Override
            public void onResponse(@NonNull Call<List<Calculation>> call,
                                   @NonNull Response<List<Calculation>> response) {
                if (response.isSuccessful() && response.body() != null)
                    callback.onSuccess(response.body());
                else
                    callback.onError("Erro ao buscar cálculos: " + response.code());
            }

            @Override
            public void onFailure(@NonNull Call<List<Calculation>> call, @NonNull Throwable t) {
                callback.onError("Falha na API: " + t.getMessage());
            }
        });
    }

    public void delete(int id, ApiCallback<Void> callback) {
        Call<Void> call = apiCalculation.delete(API_KEY, id);
        call.enqueue(new Callback<Void>() {
            @Override
            public void onResponse(@NonNull Call<Void> call, @NonNull Response<Void> response) {
                if (response.isSuccessful())
                    callback.onSuccess(null);
                else
                    callback.onError("Erro ao deletar cálculo: " + response.code());
            }

            @Override
            public void onFailure(@NonNull Call<Void> call, @NonNull Throwable t) {
                callback.onError("Falha na API: " + t.getMessage());
            }
        });
    }
}
