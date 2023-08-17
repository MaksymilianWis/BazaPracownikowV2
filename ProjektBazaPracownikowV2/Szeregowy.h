#pragma once

class Szeregowy : public Czlowiek
{
private:
public:
	virtual bool dodajDanePracownika() { return 0; };
	virtual bool usuwaniePracownika() { return 0; };
	virtual void wyswietlJednegoPracownika() {};
};