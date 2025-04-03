package com.devluiz.calculadoraapi.views;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.devluiz.calculadoraapi.R;
import com.devluiz.calculadoraapi.adapters.CalculationAdapter;
import com.devluiz.calculadoraapi.controllers.CalculationController;
import com.devluiz.calculadoraapi.interfaces.ApiCallback;
import com.devluiz.calculadoraapi.models.Calculation;

import java.util.ArrayList;
import java.util.List;

public class HistoryFragment extends Fragment {

    private CalculationController calculationController;
    private CalculationAdapter calculationAdapter;
    private RecyclerView recyclerView;

    @Override
    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_history, container, false);

        recyclerView = view.findViewById(R.id.recyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(requireContext()));

        // Inicializa o adapter com lista vazia para quando a view for criada.
        calculationAdapter = new CalculationAdapter(new ArrayList<>());
        recyclerView.setAdapter(calculationAdapter);

        return view;
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        calculationController = new CalculationController();
        calculationAdapter.setOnCalculationDeleteListener(this::deleteCalculation);
        loadHistory();
    }

    private void loadHistory() {
        calculationController.getAll(new ApiCallback<List<Calculation>>() {
            @Override
            public void onSuccess(List<Calculation> calculations) {
                if(calculations == null || calculations.isEmpty())
                    showToast("Nenhum histórico encontrado");
                requireActivity().runOnUiThread(() -> calculationAdapter.setData(calculations));
            }

            @Override
            public void onError(String message) {
                requireActivity().runOnUiThread(() -> showToast("Erro ao carregar histórico: " + message));
            }
        });
    }

    private void deleteCalculation(Calculation calculation, int position) {
        calculationController.delete(calculation.getId(), new ApiCallback<Void>() {
            @Override
            public void onSuccess(Void nothing) {
                requireActivity().runOnUiThread(() -> {
                    calculationAdapter.removeItem(position);
                    showToast("Cálculo deletado com sucesso!");
                });
            }

            @Override
            public void onError(String message) {
                requireActivity().runOnUiThread(() -> showToast("Erro ao deletar: " + message));
            }
        });
    }

    private void showToast(String message) {
        if (getContext() != null)
            Toast.makeText(getContext(), message, Toast.LENGTH_SHORT).show();
    }
}
