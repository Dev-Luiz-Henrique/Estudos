package com.devluiz.calculadoraapi.views;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

import com.devluiz.calculadoraapi.R;
import com.devluiz.calculadoraapi.controllers.CalculationController;
import com.devluiz.calculadoraapi.interfaces.ApiCallback;

public class CalculatorFragment extends Fragment {

    private CalculationController calculationController;
    private EditText edtValueA, edtValueB;
    private Button buttonAdd, buttonSubtract, buttonMultiply, buttonDivide;

    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        return inflater.inflate(R.layout.fragment_calculator, container, false);
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        calculationController = new CalculationController();

        edtValueA = view.findViewById(R.id.edtValueA);
        edtValueB = view.findViewById(R.id.edtValueB);
        buttonAdd = view.findViewById(R.id.buttonAdd);
        buttonSubtract = view.findViewById(R.id.buttonSubtract);
        buttonMultiply = view.findViewById(R.id.buttonMultiply);
        buttonDivide = view.findViewById(R.id.buttonDivide);

        buttonAdd.setOnClickListener(v -> calculate("+"));
        buttonSubtract.setOnClickListener(v -> calculate("-"));
        buttonMultiply.setOnClickListener(v -> calculate("*"));
        buttonDivide.setOnClickListener(v -> calculate("/"));
    }

    private void calculate(String operation) {
        String valueA = edtValueA.getText().toString();
        String valueB = edtValueB.getText().toString();

        // Verifica valores em Branco
        if (valueA.isEmpty() || valueB.isEmpty()) {
            showToast("Preencha os dois valores!");
            return;
        }

        try {
            // Verifica se são numeros validos (Se tiver caractres resulta em uma exception)
            double a = Double.parseDouble(valueA);
            double b = Double.parseDouble(valueB);

            calculationController.calculateAndCreate(a, b, operation, new ApiCallback<Integer>() {
                @Override
                public void onSuccess(Integer id) {
                    requireActivity().runOnUiThread(() ->
                            showToast("Dados armazenados com sucesso, ID de Armazenamento " + id)
                    );

                    // Limpa os campos apenas em caso de sucesso
                    edtValueA.setText("");
                    edtValueB.setText("");
                }

                @Override
                public void onError(String message) {
                    requireActivity().runOnUiThread(() -> showToast("Erro: " + message));
                }
            });

        } catch (NumberFormatException e) {
            showToast("Digite números válidos!");
        } catch (Exception e) {
            showToast("Ocorreu um inesperado ao realizar o cálculo!");
        }
    }

    // Função para centralizar a exibição de mensagens e evitar repetição
    private void showToast(String message) {
        if (getContext() != null)
            Toast.makeText(getContext(), message, Toast.LENGTH_SHORT).show();
    }
}
