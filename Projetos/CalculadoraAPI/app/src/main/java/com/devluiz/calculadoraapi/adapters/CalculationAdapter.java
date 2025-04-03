package com.devluiz.calculadoraapi.adapters;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.devluiz.calculadoraapi.R;
import com.devluiz.calculadoraapi.models.Calculation;

import java.util.List;

public class CalculationAdapter extends RecyclerView.Adapter<CalculationAdapter.CalculationViewHolder> {

    private List<Calculation> calculations;

    public CalculationAdapter(List<Calculation> calculations) {
        this.calculations = calculations;
    }

    @NonNull
    @Override
    public CalculationViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext())
                .inflate(R.layout.item_history, parent, false);
        return new CalculationViewHolder(view, onCalculationDeleteListener);
    }

    @Override
    public void onBindViewHolder(@NonNull CalculationViewHolder holder, int position) {
        Calculation calculation = calculations.get(position);
        holder.bind(calculation, position);
    }

    @Override
    public int getItemCount() {
        return calculations.size();
    }

    public void removeItem(int position) {
        calculations.remove(position);
        notifyItemRemoved(position);
    }

    public void setData(List<Calculation> newCalculations) {
        this.calculations.clear();
        this.calculations.addAll(newCalculations);
        notifyDataSetChanged();
    }

    /////////////////////////////////////////////////////

    private OnCalculationDeleteListener onCalculationDeleteListener;

    public interface OnCalculationDeleteListener {
        void onDelete(Calculation calculation, int position);
    }

    public void setOnCalculationDeleteListener(OnCalculationDeleteListener listener) {
        this.onCalculationDeleteListener = listener;
    }

    /////////////////////////////////////////////////////

    public static class CalculationViewHolder extends RecyclerView.ViewHolder {

        private final TextView txtId, txtDate, txtValueA, txtValueB, txtOperation, txtResult;
        private final ImageButton btnDelete;
        private final OnCalculationDeleteListener deleteListener;

        public CalculationViewHolder(@NonNull View itemView, OnCalculationDeleteListener listener) {
            super(itemView);
            txtId = itemView.findViewById(R.id.txtId);
            txtDate = itemView.findViewById(R.id.txtDate);
            txtValueA = itemView.findViewById(R.id.txtValueA);
            txtValueB = itemView.findViewById(R.id.txtValueB);
            txtOperation = itemView.findViewById(R.id.txtOperation);
            txtResult = itemView.findViewById(R.id.txtResult);
            btnDelete = itemView.findViewById(R.id.btnDelete);
            deleteListener = listener;
        }

        public void bind(Calculation calculation, int position) {
            txtId.setText(String.valueOf(calculation.getId()));
            txtDate.setText(calculation.getFormattedDate());
            txtValueA.setText(String.format("%.2f", calculation.getValueA()));
            txtValueB.setText(String.format("%.2f", calculation.getValueB()));
            txtOperation.setText(calculation.getOperation());
            txtResult.setText(String.format("%.2f", calculation.getResult()));

            btnDelete.setOnClickListener(v -> {
                if (deleteListener != null)
                    deleteListener.onDelete(calculation, position);
            });
        }
    }
}
