/*

	Pac-Man
	Copyright SAUTER Robin and Joeffrey VILLERONCE 2018-2019 (robin.sauter@orange.fr)
	last modification on this file on version:0.15

	You can check for update on github.com -> https://github.com/phoenixcuriosity/Pac-Man

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "Texture.h"
#include "Pac_Man_lib.h"


///////////////////////////// Texture //////////////////////////////
/* TEXTURE :: STATIC */
void Texture::loadImage(SDL_Renderer*& renderer, std::vector<Texture*>& tabTexture, Uint8 statescreen, Uint8 select,
	const std::string &path, const std::string &msg, Uint8 alpha, int x, int y, unsigned int w, unsigned int h, Uint8 cnt) {


	int xt = 0, yt = 0, wt = 0, ht = 0;
	if (x != -1 && y != -1)
		xt = x, yt = y;

	SDL_Texture* newTexture = nullptr;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (w == 0 && h == 0) {
		wt = loadedSurface->w;
		ht = loadedSurface->h;
	}
	else {
		wt = w;
		ht = h;
	}

	if (loadedSurface != nullptr) {
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture != nullptr) {
			if (alpha != nonTransparent) {
				if (SDL_SetTextureAlphaMod(newTexture, alpha) != 0)
					IHM::logSDLError(std::cout, "alpha : ");
			}
			centrage(xt, yt, wt, ht, cnt);
			tabTexture.push_back(new Texture(newTexture, msg, statescreen, select, xt, yt, wt, ht, alpha, cnt));
		}
		else
			IHM::logfileconsole("___________ERROR : loadImage : cannot create Texture from : " + path);
		SDL_FreeSurface(loadedSurface);
	}
	else
		IHM::logfileconsole("___________ERROR : loadImage : path or image are corrupt : " + path);
}
void Texture::centrage(int& xc, int& yc, int iW, int iH, Uint8 cnt) {
	switch (cnt) {
	case nocenter:
		break;
	case center_x:
		xc -= (iW / 2);
		break;
	case center_y:
		yc -= (iH / 2);
		break;
	case center:
		xc -= (iW / 2);
		yc -= (iH / 2);
		break;
	}
}

/* TEXTURE :: METHODES */
Texture::Texture(SDL_Texture* image, const std::string& msg, Uint8 statescreen, Uint8 select,
	unsigned int x, unsigned int y, int w, int h, Uint8 alpha, Uint8 center)
	: _texture(image), _dst(rectangle(x, y, w, h)), _name(msg),
	_statescreen(statescreen), _select(select), _alpha(alpha), _center(center)
{
}
Texture::~Texture() {
	if (_texture != nullptr) {
		SDL_DestroyTexture(_texture);
		_texture = nullptr;
	}
}
SDL_Rect Texture::rectangle(int x, int y, int w, int h) {
	SDL_Rect rectangle;
	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = w;
	rectangle.h = h;
	return rectangle;
}
void Texture::render(SDL_Renderer*& renderer, int x, int y) {
	if (x != -1 && y != -1) {
		_dst.x = x;
		_dst.y = y;
	}
	SDL_RenderCopy(renderer, _texture, NULL, &_dst);
}
void Texture::renderTextureTestStates(SDL_Renderer*& renderer, Uint8 statescreen, Uint8 select, int x, int y) {
	if (_statescreen == statescreen && _select == select)
		render(renderer, x, y);
}
void Texture::renderTextureTestStatesAngle(SDL_Renderer*& renderer, Uint8 statescreen, int x, int y, unsigned int angle) {
	if (_statescreen == statescreen) {
		if (x != -1 && y != -1) {
			_dst.x = x;
			_dst.y = y;
		}
		SDL_RenderCopyEx(renderer, _texture, NULL, &_dst, angle, NULL, SDL_FLIP_NONE);
	}
}
bool Texture::renderTextureTestString(SDL_Renderer*& renderer, const std::string& msg, int xc, int yc) {
	if (_name.compare(msg) == 0) {
		render(renderer, xc, yc);
		return true;
	}
	return false;
}
bool Texture::renderTextureTestStringAndStates(SDL_Renderer*& renderer, const std::string& msg, Uint8 statescreen, int xc, int yc) {
	if (_name.compare(msg) == 0 && _statescreen == statescreen) {
		render(renderer, xc, yc);
		return true;
	}
	return false;
}
bool Texture::TextureTestString(const std::string& msg) {
	if (_name.compare(msg) == 0)
		return true;
	return false;
}
SDL_Texture* Texture::GETtexture() const {
	return _texture;
}
SDL_Texture* Texture::GETtextureNonConst(){
	return _texture;
}
SDL_Rect Texture::GETdst()const {
	return _dst;
}
int Texture::GETdstx()const {
	return _dst.x;
}
int Texture::GETdsty()const {
	return _dst.y;
}
int Texture::GETdstw()const {
	return _dst.w;
}
int Texture::GETdsth()const {
	return _dst.h;
}
std::string Texture::GETname() const {
	return _name;
}
Uint8 Texture::GETstatescreen() const {
	return _statescreen;
}
Uint8 Texture::GETselect() const {
	return _select;
}
Uint8 Texture::GETalpha() const {
	return _alpha;
}
Uint8 Texture::GETcenter() const {
	return _center;
}
void Texture::SETtexture(SDL_Texture* texture) {
	if (_texture != texture) {
		if (_texture != nullptr) {
			SDL_DestroyTexture(_texture);
			_texture = nullptr;
		}
		_texture = texture;
	}
}
void Texture::SETdstx(int x) {
	_dst.x = x;
}
void Texture::SETdsty(int y) {
	_dst.y = y;
}
void Texture::SETdstw(int w) {
	_dst.w = w;
}
void Texture::SETdsth(int h) {
	_dst.h = h;
}
void Texture::SETname(std::string msg) {
	_name = msg;
}
void Texture::SETalpha(Uint8 alpha) {
	if (_alpha != alpha) {
		_alpha = alpha;
		if (SDL_SetTextureAlphaMod(_texture, _alpha) != 0)
			IHM::logSDLError(std::cout, "alpha : ");
	}
}
void Texture::SETcenter(Uint8 center) {
	if (_center != center) {
		_center = center;
		centrage(_dst.x, _dst.y, _dst.w, _dst.h, _center);
	}
}



///////////////////////////// Texte //////////////////////////////
/* Texte :: STATIC */
SDL_Texture* Texte::createSDL_TextureFromTexte(SDL_Renderer*& renderer, Uint8 type, const std::string &message, SDL_Color color, SDL_Color colorback, TTF_Font* font) {
	SDL_Surface *surf = nullptr;

	if (type == blended)
		surf = TTF_RenderText_Blended(font, message.c_str(), color);
	else if (type == shaded)
		surf = TTF_RenderText_Shaded(font, message.c_str(), color, colorback);

	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == nullptr)
		IHM::logfileconsole("___________ERROR : renderTextShaded nullptr for : " + message);
	SDL_FreeSurface(surf);

	return texture;
}
void Texte::loadTexte(SDL_Renderer*& renderer, TTF_Font* font[], Uint8 statescreen, Uint8 select,
	std::vector<Texte*>& tabTexte, Uint8 type, const std::string &msg,
	SDL_Color color, SDL_Color backcolor, Uint8 size, int x, int y, Uint8 alpha, Uint8 cnt) {

	SDL_Texture *image = createSDL_TextureFromTexte(renderer, type, msg, color, backcolor, font[size]);
	if (alpha != nonTransparent)
		SDL_SetTextureAlphaMod(image, alpha);
	int xc = x, yc = y, iW = 0, iH = 0;
	SDL_QueryTexture(image, NULL, NULL, &iW, &iH);
	centrage(xc, yc, iW, iH, cnt);
	tabTexte.push_back(new Texte(image, msg, statescreen, select, xc, yc, iW, iH,
		type, color, backcolor, size, alpha, cnt));
}
void Texte::writeTexte(SDL_Renderer*& renderer, TTF_Font* font[], Uint8 type, const std::string &msg,
	SDL_Color color, SDL_Color backcolor, Uint8 size, unsigned int x, unsigned int y, Uint8 cnt) {
	SDL_Texture *image = createSDL_TextureFromTexte(renderer, type, msg, color, backcolor, font[size]);
	
	int xc = x, yc = y, iW = 0, iH = 0;
	SDL_QueryTexture(image, NULL, NULL, &iW, &iH);
	centrage(xc, yc, iW, iH, cnt);

	SDL_Rect dst;
	dst.x = xc;
	dst.y = yc;
	dst.w = iW;
	dst.h = iH;
	SDL_RenderCopy(renderer, image, NULL, &dst);

	SDL_DestroyTexture(image);
}


/* Texte :: METHODES */
Texte::Texte(SDL_Texture* image, const std::string& msg, Uint8 statescreen, Uint8 select, int x, int y, int w, int h,
	Uint8 type, SDL_Color txtcolor, SDL_Color backcolor, Uint8 size, Uint8 alpha, Uint8 center) :
	Texture(image, msg, statescreen, select, x, y, w, h, alpha, center), _type(type), _txtcolor(txtcolor), _backcolor(backcolor),
	_size(size)
{
}
Uint8 Texte::GETtype()const {
	return _type;
}
SDL_Color Texte::GETtxtcolor() const {
	return _txtcolor;
}
SDL_Color Texte::GETbackcolor() const {
	return _backcolor;
}
Uint8 Texte::GETsize()const {
	return _size;
}
void Texte::SETname(std::string msg, SDL_Renderer*& renderer, TTF_Font* font[]) {
	if (this->GETname().compare(msg) != 0) {
		this->Texture::SETname(msg);
		this->SETtexture(createSDL_TextureFromTexte(renderer, _type, this->GETname(), _txtcolor, _backcolor, font[_size]));
		resizeTexte();
	}
}
void Texte::SETtype(Uint8 type, SDL_Renderer*& renderer, TTF_Font *font[]) {
	if (type != _type) {
		_type = type;
		this->SETtexture(createSDL_TextureFromTexte(renderer, _type, this->GETname(), _txtcolor, _backcolor, font[_size]));
	}
}
void Texte::SETsize(Uint8 size, SDL_Renderer*& renderer, TTF_Font *font[]) {
	if (size != _size) {
		_size = size;
		this->SETtexture(createSDL_TextureFromTexte(renderer, _type, this->GETname(), _txtcolor, _backcolor, font[_size]));
		resizeTexte();
	}
}
void Texte::SETtxtcolor(SDL_Color txtcolor, SDL_Renderer*& renderer, TTF_Font *font[]) {
	if (!isSameColor(txtcolor, _txtcolor)) {
		_txtcolor = txtcolor;
		this->SETtexture(createSDL_TextureFromTexte(renderer, _type, this->GETname(), _txtcolor, _backcolor, font[_size]));
	}
}
void Texte::SETbackcolor(SDL_Color backcolor, SDL_Renderer*& renderer, TTF_Font *font[]) {
	if(!isSameColor(backcolor, _backcolor)) {
		_backcolor = backcolor;
		this->SETtexture(createSDL_TextureFromTexte(renderer, _type, this->GETname(), _txtcolor, _backcolor, font[_size]));
	}
}
bool Texte::isSameColor(SDL_Color color1, SDL_Color color2) const {
	if (color1.a != color2.a || color1.b != color2.b || color1.g != color2.g || color1.r != color2.r)
		return false;
	else
		return true;
}
void Texte::resizeTexte() {
	int xc = 0, yc = 0, iW = 0, iH = 0;

	switch (this->GETcenter()) {
	case nocenter:
		xc = this->GETdstx();
		yc = this->GETdsty();
		break;
	case center_x:
		xc = this->GETdstx() + this->GETdstw() / 2;
		yc = this->GETdsty();
		break;
	case center_y:
		xc = this->GETdstx();
		yc = this->GETdsty() + this->GETdsth() / 2;
		break;
	case center:
		xc = this->GETdstx() + this->GETdstw() / 2;
		yc = this->GETdsty() + this->GETdsth() / 2;
		break;
	}

	SDL_QueryTexture(this->GETtextureNonConst(), NULL, NULL, &iW, &iH);
	centrage(xc, yc, iW, iH, this->GETcenter());
	this->SETdstx(xc); this->SETdsty(yc); this->SETdstw(iW); this->SETdsth(iH);
}





///////////////////////////// Button //////////////////////////////
/* BUTTONS :: STATIC */
void Button::createbutton(SDL_Renderer*& renderer, TTF_Font* font[], Uint8 statescreen, Uint8 select, 
	std::vector<Button*>& tabbutton, Uint8 type, const std::string& msg,
	SDL_Color color, SDL_Color backcolor, Uint8 size, int x, int y, Uint8 alpha, Uint8 cnt) {
	int iW = 0, iH = 0;
	unsigned int i = 0;

	SDL_Texture *image = nullptr;
	SDL_Texture *imageOn = nullptr;
	
	image = createSDL_TextureFromTexte(renderer, type, msg, color, backcolor, font[size]);
	imageOn = createSDL_TextureFromTexte(renderer, type, msg, color, { 64,128,64,255 }, font[size]);
	if (alpha != nonTransparent) {
		SDL_SetTextureAlphaMod(image, alpha);
		SDL_SetTextureAlphaMod(imageOn, alpha);
	}
	SDL_QueryTexture(image, NULL, NULL, &iW, &iH);
	centrage(x, y, iW, iH, cnt);
	tabbutton.push_back(new Button(image, msg, statescreen, select, x, y, iW, iH,
				type, color, backcolor, size, alpha, imageOn, cnt));

	IHM::logfileconsole("Create Button n:" + std::to_string(i) + " msg = " + tabbutton[i]->GETname() + " Success");
}


/* BUTTONS :: METHODES */
Button::Button(SDL_Texture* image, const std::string& msg, Uint8 statescreen, Uint8 select, int x, int y, int w, int h,
	Uint8 type, SDL_Color txtcolor, SDL_Color backcolor, Uint8 size, Uint8 alpha, SDL_Texture* imageOn, Uint8 center)
	: Texte(image, msg, statescreen, select, x, y, w, h, type, txtcolor, backcolor, size, alpha, center),
	_imageOn(imageOn), _on(false)
{

}
Button::~Button() {
	if (_imageOn != nullptr) {
		SDL_DestroyTexture(_imageOn);
		_imageOn = nullptr;
	}
}
unsigned int Button::searchButton(std::string msg, Uint8 statescreen, signed int x, signed int y) {
	if (statescreen == this->GETstatescreen()) {
		if (x >= this->GETdstx() && x <= this->GETdstx() + this->GETdstw()) {
			if (y >= this->GETdsty() && y <= this->GETdsty() + this->GETdsth()) {
				if (this->GETname().compare(msg) == 0)
					return 1;
			}
		}
	}
	return 0;
}
unsigned int Button::searchButtonName(std::string& msg, Uint8 statescreen) {
	if (statescreen == this->GETstatescreen()) {
		if (this->GETname().compare(msg) == 0)
			return 1;
	}
	return 0;
}
void Button::resetOnStatescreen(Uint8 select, unsigned int selectnothing) {
	if (this->GETselect() != select && this->GETselect() != selectnothing)
		_on = false;
}
void Button::resetOnPlayer(unsigned int selectplayer, std::vector<std::string> tabPlayerName) {
	for (unsigned int i = 0; i < tabPlayerName.size(); i++) {
		if (i != selectplayer && this->GETname().compare(tabPlayerName[i]) == 0)
			_on = false;
	}
}
bool Button::renderButton(SDL_Renderer*& renderer, Uint8 statescreen) {
	if (this->GETstatescreen() == statescreen) {
		if (_on)
			SDL_RenderCopy(renderer, _imageOn, NULL, &this->GETdst());
		else
			SDL_RenderCopy(renderer, this->GETtexture(), NULL, &this->GETdst());
		return true;
	}
	return false;
}
bool Button::renderButtonTestString(SDL_Renderer*& renderer, Uint8 statescreen, std::string& msg, int newx, int newy, Uint8 cnt) {
	if (this->GETstatescreen() == statescreen && this->GETname().compare(msg) == 0) {
		if (newx != -1 && newy != -1) {
			centrage(newx, newy, this->GETdstw(), this->GETdsth(), cnt);
			this->SETdstx(newx);
			this->SETdstx(newx);
		}
		if (_on)
			SDL_RenderCopy(renderer, _imageOn, NULL, &this->GETdst());
		else
			SDL_RenderCopy(renderer, this->GETtexture(), NULL, &this->GETdst());
		return true;
	}
	return false;
}
void Button::changeOn() {
	_on = !_on;
}
SDL_Texture* Button::GETimageOn() const {
	return _imageOn;
}
bool Button::GETon() const {
	return _on;
}
void Button::SETname(std::string msg) {
	if (this->GETname().compare(msg) != 0) {
		IHM::logfileconsole("___ERROR : Button::SETname() : Le nom d'un bouton ne peut pas changer après initialisation");
	}
}
void Button::SETon(bool state) {
	_on = state;
}
void Button::SETalpha(Uint8 alpha) {
	this->SETalpha(alpha);
	if (SDL_SetTextureAlphaMod(this->GETtextureNonConst(), this->GETalpha()) != 0)
		IHM::logSDLError(std::cout, "alpha : ");
	if (SDL_SetTextureAlphaMod(_imageOn, this->GETalpha()) != 0)
		IHM::logSDLError(std::cout, "alpha : ");
}