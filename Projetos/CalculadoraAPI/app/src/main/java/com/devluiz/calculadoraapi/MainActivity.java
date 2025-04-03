package com.devluiz.calculadoraapi;

import android.os.Bundle;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentTransaction;

import com.devluiz.calculadoraapi.views.CalculatorFragment;
import com.devluiz.calculadoraapi.views.HistoryFragment;

public class MainActivity extends AppCompatActivity {

    private Button btnCalculator, btnHistory;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btnCalculator = findViewById(R.id.btnCalculator);
        btnHistory = findViewById(R.id.btnHistory);

        loadFragment(new CalculatorFragment());

        btnCalculator.setOnClickListener(v -> loadFragment(new CalculatorFragment()));
        btnHistory.setOnClickListener(v -> loadFragment(new HistoryFragment()));
    }

    private void loadFragment(Fragment fragment) {
        FragmentTransaction transaction = getSupportFragmentManager().beginTransaction();
        transaction.replace(R.id.fragment_container, fragment);
        transaction.addToBackStack(null);
        transaction.commit();
    }
}
