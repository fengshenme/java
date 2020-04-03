package com.example.demoone.c;

import android.content.Context;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.example.demoone.R;

public class ToastActivity extends AppCompatActivity {


    private Button btn_toast;
    private Context mContext;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_toast);

        mContext = ToastActivity.this;
        btn_toast = findViewById(R.id.btn_toast);
        btn_toast.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                midToast("提莫队长，正在送命~", Toast.LENGTH_SHORT);
            }
        });

    }

    private void midToast(String str, int showTime) {
        LayoutInflater inflater = getLayoutInflater();
        View view = inflater.inflate(R.layout.view_toast_custom,  (ViewGroup) findViewById(R.id.lly_toast));
        ImageView img_logo =  view.findViewById(R.id.img_logo);
        TextView tv_msg = view.findViewById(R.id.tv_msg);
        tv_msg.setText(str);
        Toast toast = new Toast(mContext);
        toast.setGravity(Gravity.CENTER, 0, 0);
        toast.setDuration(showTime);
        toast.setView(view);
        toast.show();
    }

}
