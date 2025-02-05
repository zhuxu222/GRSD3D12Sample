struct PSInput
{
	float4 position : SV_POSITION;
	float2 uv : TEXCOORD;
	float3 nor	: NORMAL;
};

cbuffer MVPBuffer : register(b0)
{
	float4x4 m_MVP;
};

Texture2D g_texture : register(t0);
SamplerState g_sampler : register(s0);

PSInput VSMain(float4 position : POSITION, float2 uv : TEXCOORD,float3 nor:NORMAL)
{
	PSInput result;
	result.position = mul(position, m_MVP);
	result.uv = uv;
	result.nor=nor;

	return result;
}

float4 PSMain(PSInput input) : SV_TARGET
{
	return g_texture.Sample(g_sampler, input.uv);
}
