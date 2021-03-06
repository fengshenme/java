package com.example.android_demo.f;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;

import androidx.appcompat.app.AppCompatActivity;

import com.example.android_demo.R;

/**
 * 通过intent进行消息发送
 */
public class MessageActivity extends AppCompatActivity {

    private Button btnregister;
    private EditText editname;
    private RadioGroup rad;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_message);

        btnregister = findViewById(R.id.btnregister);
        editname = findViewById(R.id.editname);
        rad = findViewById(R.id.radioGroup);
        btnregister.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String name,sex = "";
                Intent it = new Intent(MessageActivity.this,Message2Activity.class);

                name = editname.getText().toString();

                //遍历RadioGroup找出被选中的单选按钮
                for(int i = 0;i < rad.getChildCount();i++)
                {
                    RadioButton rd = (RadioButton)rad.getChildAt(i);
                    if(rd.isChecked())
                    {
                        sex = rd.getText().toString();
                        break;
                    }
                }

                //新建Bundle对象,并把数据写入
                Bundle bd = new Bundle();
                bd.putCharSequence("user",name);
                bd.putCharSequence("sex",sex);

                //将数据包Bundle绑定到Intent上
                it.putExtras(bd);
                startActivity(it);
                //关闭第一个Activity
                finish();

            }
        });
    }

}
