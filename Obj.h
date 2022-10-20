
class Obj{
	public:
	int wx,wy,x,y,w,h,awx;Texture t; Sprite spr; bool hit, shot;
	
	Obj(int _wx, int _wy, int _x, int _y, int _w, int _h, const String iSrc){
		awx=_wx; wx=_wx, wy=_wy, x=_x, y=_y, w=_w, h=_h,
		shot=0; hit=0;
		
		t.loadFromFile(iSrc);
		spr.setTexture(t);
	}
	void show(RenderWindow &window){
		spr.setTextureRect(IntRect(wx,wy,w,h));
		spr.setPosition(x,y);
		if(!hit) window.draw(spr);
	}
};
