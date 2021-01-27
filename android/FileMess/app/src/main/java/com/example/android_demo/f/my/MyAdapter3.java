package com.example.android_demo.f.my;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import com.example.android_demo.R;

import java.util.List;

/**
 * Created by Jay on 2015/9/6 0006.
 */
public class MyAdapter3 extends BaseAdapter{

    private List<Data> mData;
    private Context mContext;

    public MyAdapter3(List<Data> mData, Context mContext) {
        this.mData = mData;
        this.mContext = mContext;
    }

    @Override
    public int getCount() {
        return mData.size();
    }

    @Override
    public Object getItem(int position) {
        return null;
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder viewHolder ;
        if(convertView == null){
            convertView = LayoutInflater.from(mContext).inflate(R.layout.list_item_a,parent,false);
            viewHolder = new ViewHolder();;
            viewHolder.txt_item_title = convertView.findViewById(R.id.txt_item_title);
            convertView.setTag(viewHolder);
        }else{
            viewHolder = (ViewHolder) convertView.getTag();
        }
        viewHolder.txt_item_title.setText(mData.get(position).getNew_title());
        return convertView;
    }

    private class ViewHolder{
        TextView txt_item_title;
    }

}