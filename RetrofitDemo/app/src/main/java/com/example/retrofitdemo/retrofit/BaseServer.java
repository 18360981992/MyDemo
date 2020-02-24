package com.example.retrofitdemo.retrofit;


import com.example.retrofitdemo.bean.TagBean;
import com.example.retrofitdemo.util.Dog;

import java.util.ArrayList;

import io.reactivex.Observer;
import io.reactivex.annotations.NonNull;
import io.reactivex.disposables.Disposable;

/**
 * Created by mypc on 2018/1/6.
 *
 * 子类的共有方法
 */

public abstract class BaseServer implements Observer<String> {

    private TagBean mTagBean;

    private static ArrayList<TagBean> mDisposables = new ArrayList<>();

    public abstract void onSuccess(String myBean);

    public abstract void onErroy(String ss);

    public BaseServer(TagBean mTagBean) {
        this.mTagBean = mTagBean;
    }

    public static void removeTagBean(TagBean removeTagBean) {
        if(removeTagBean != null){
            mDisposables.remove(removeTagBean);
        }
    }

    public static void disposeAll() {
        Dog.d("jba","disposeAll disposables size = "+mDisposables.size());
        if(!mDisposables.isEmpty()){
            for (TagBean dis : mDisposables) {
                dis.getDisposable().dispose();
            }
        }
        mDisposables.clear();
    }

    @Override
    public void onError(Throwable e) {
        onErroy("请求失败");
    }

    @Override
    public void onNext(String myBean) {
        onSuccess(myBean);
    }

    @Override
    public void onSubscribe(@NonNull Disposable d) {
        Dog.d("jba","onSubscribe...");
        if(mTagBean != null){
            mTagBean.setDisposable(d);
            Dog.d("jba","start tagBean = "+ mTagBean);
            mDisposables.add(mTagBean);
        }
    }

    @Override
    public void onComplete() {

    }
}
