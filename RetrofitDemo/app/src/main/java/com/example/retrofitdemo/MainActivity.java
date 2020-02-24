package com.example.retrofitdemo;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.core.app.ActivityCompat;

import com.example.retrofitdemo.api.APIs;
import com.example.retrofitdemo.appliction.DashApplication;
import com.example.retrofitdemo.base.BaseMVPActivity;
import com.example.retrofitdemo.bean.TagBean;
import com.example.retrofitdemo.presenter.MyPresenter;
import com.example.retrofitdemo.retrofit.BaseServer;
import com.example.retrofitdemo.retrofit.MyInterfaces;
import com.example.retrofitdemo.util.Dog;
import com.example.retrofitdemo.util.ImageUtils;
import com.example.retrofitdemo.util.MyUtils;
import com.example.retrofitdemo.view.ForbidClickListener;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

import io.reactivex.Observable;
import io.reactivex.android.schedulers.AndroidSchedulers;
import io.reactivex.schedulers.Schedulers;
import okhttp3.MediaType;
import okhttp3.MultipartBody;
import okhttp3.RequestBody;

import static com.example.retrofitdemo.retrofit.RetrofitFacety.apiService;
import static com.example.retrofitdemo.util.ImageUtils.getPhotos;

public class MainActivity extends BaseMVPActivity<MainActivity, MyPresenter<MainActivity>> {

    private Button btn;
    private TextView tv;
    private Button btup;

    @Override
    public MyPresenter<MainActivity> initPresenter() {
        if (myPresenter == null) {
            myPresenter = new MyPresenter();
        }
        return myPresenter;
    }

    List<MultipartBody.Part> photos = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Dog.d("jba","onCreate...");
        setContentView(R.layout.activity_main);
        initView();

        btn.setOnClickListener(new ForbidClickListener() {
            @Override
            public void forbidClick(View v) {

                myPresenter.getPreContent(APIs.wxnew, new MyInterfaces() {
                    @Override
                    public void chenggong(String json) {
                        tv.setText("json===" + json);
                    }

                    @Override
                    public void shibai(String ss) {
                        MyUtils.setToast(ss);
                    }
                });

                myPresenter.getPreContent(APIs.wxnew1, new MyInterfaces() {
                    @Override
                    public void chenggong(String json) {
                        tv.setText("json===" + json);
                    }

                    @Override
                    public void shibai(String ss) {
                        MyUtils.setToast(ss);
                    }
                });
//                for (int i = 0; i < 1; i ++){
//
//                }
            }
        });

        // 上传多文件
        btup.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 6.0权限适配
                if (ActivityCompat.checkSelfPermission(MainActivity.this, Manifest.permission.WRITE_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) {
                    ActivityCompat.requestPermissions(MainActivity.this,new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE}, DashApplication.WRITE_EXTERNAL_STORAGE);
                }else{
                    // 启动相册
                    Intent intent = new Intent(Intent.ACTION_PICK);
                    intent.setType("image/*");
                    startActivityForResult(intent, 1000);
                }
            }
        });

    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        Dog.d("jba","onDestroy...");
        BaseServer.disposeAll();
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if(requestCode==DashApplication.WRITE_EXTERNAL_STORAGE){
            if(grantResults[0]!=-1){
                // 启动相册
                Intent intent = new Intent(Intent.ACTION_PICK);
                intent.setType("image/*");
                startActivityForResult(intent, 1000);
            }else{
                return;
            }
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        // 正面照的请求结果  相册
        if(requestCode==1000&resultCode==RESULT_OK){
            Uri uri = data.getData();
            File fileUri = ImageUtils.getFileUri(uri, this); // 将uri转成file
            // 将相册中获取到的照片重新选择路径存储 这里是用于适配机型的
            File photos1 = getPhotos(fileUri);
            Dog.i("jba","photos=="+ photos1.toString());
            tv.setText(photos1.toString());

            photos.clear();
            long time = System.currentTimeMillis();
            TagBean tagBean = new TagBean(time, "");

            setPhotos(photos1,"identityFrontPic");
            setPhotos(photos1,"identityBackPic");
            setPhotos(photos1,"headerPic");
            setPhotos(photos1,"businessPic");
            Observable<String> responseBodyCall = apiService.uploadFile(photos);
            responseBodyCall.subscribeOn(Schedulers.io())
                    .observeOn(AndroidSchedulers.mainThread())
                    .subscribe(new BaseServer(tagBean) {
                        @Override
                        public void onSuccess(String json) {
                            Dog.d("jba","end tagBean = "+ tagBean);
                            removeTagBean(tagBean);
                            tv.setText(json);
                        }

                        @Override
                        public void onErroy(String ss) {
                            tv.setText(ss);
                        }
                    });
        }
    }

    // 设置file类型
    private void setPhotos(File file, String key) {
        RequestBody requestFile = RequestBody.create(MediaType.parse("multipart/form-data"), file);
        MultipartBody.Part body = MultipartBody.Part.createFormData(key, file.getName(), requestFile);
        photos.add(body);
    }

    private void initView() {
        btn = (Button) findViewById(R.id.btn);
        btup = (Button) findViewById(R.id.btup);
        tv = (TextView) findViewById(R.id.tv);
    }





}
