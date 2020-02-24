package com.example.retrofitdemo.bean;

import io.reactivex.disposables.Disposable;

public class TagBean {
    long time;
    String tag;
    Disposable disposable;

    public TagBean(long time, String tag) {
        this.time = time;
        this.tag = tag;
    }

    public TagBean(long time, String tag, Disposable disposable) {
        this.time = time;
        this.tag = tag;
        this.disposable = disposable;
    }

    public void setTime(long time) {
        this.time = time;
    }

    public void setTag(String tag) {
        this.tag = tag;
    }

    public void setDisposable(Disposable disposable) {
        this.disposable = disposable;
    }

    public long getTime() {
        return time;
    }

    public String getTag() {
        return tag;
    }

    public Disposable getDisposable() {
        return disposable;
    }

    @Override
    public String toString() {
        return "TagBean{" +
                "time=" + time +
                ", tag='" + tag + '\'' +
                ", disposable=" + disposable +
                '}';
    }
}
