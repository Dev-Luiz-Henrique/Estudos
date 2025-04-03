package com.devluiz.calculadoraapi.interfaces;

public interface ApiCallback<T> {
    void onSuccess(T result);
    void onError(String message);
}
