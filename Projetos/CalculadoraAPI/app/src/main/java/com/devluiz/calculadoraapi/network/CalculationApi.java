package com.devluiz.calculadoraapi.network;

import androidx.annotation.NonNull;

import com.devluiz.calculadoraapi.models.Calculation;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonDeserializer;
import com.google.gson.JsonPrimitive;
import com.google.gson.JsonSerializer;

import java.time.LocalDateTime;
import java.util.List;

import retrofit2.Call;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;
import retrofit2.http.Body;
import retrofit2.http.DELETE;
import retrofit2.http.GET;
import retrofit2.http.POST;
import retrofit2.http.Query;
public interface CalculationApi {

    @POST("api/Calculadora")
    Call<Integer> post(
            @Query("apikey") String apiKey,
            @Body Calculation calculation
    );

    @GET("api/Calculadora")
    Call<List<Calculation>> get(
            @Query("apikey") String apiKey
    );

    @DELETE("api/Calculadora")
    Call<Void> delete(
            @Query("apikey") String apiKey,
            @Query("id") int id
    );

    // Método de fábrica para criar uma instância do Retrofit
    @NonNull
    static CalculationApi create() {
        // Configurar o Gson para lidar com a conversão dos formatos de data
        Gson gson = new GsonBuilder()
                .registerTypeAdapter(LocalDateTime.class, (JsonDeserializer<LocalDateTime>)
                        (json, type, context) -> LocalDateTime.parse(json.getAsString())
                )
                .registerTypeAdapter(LocalDateTime.class, (JsonSerializer<LocalDateTime>)
                        (src, type, context) -> new JsonPrimitive(src.toString())
                )
                .create();

        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl("https://localhost:8080/calcapi/")
                .addConverterFactory(GsonConverterFactory.create(gson))
                .build();

        return retrofit.create(CalculationApi.class);
    }
}
